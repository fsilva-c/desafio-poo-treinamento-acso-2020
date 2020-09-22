#include "data.hpp"
#include "cidade.hpp"
#include "saude.hpp"
#include "pessoa.hpp"
#include "mulher.hpp"
#include "homem.hpp"
#include <ostream>
#include <string>
#include <typeinfo>
#include <time.h>

bool Cidade::addPessoa(Pessoa *__pessoa)
{

    if(populacao_size == 100 || __pessoa == NULL)    return false;

    Cep endereco = gerarCep();
    mapa[endereco.x][endereco.y] = __pessoa;
    populacao_size++;
    return true;
}

void Cidade::popular(unsigned &__m_sadias, unsigned &__m_infectadas, unsigned &__h_sadios, unsigned &__h_infectados)
{
    srand(time(NULL));

    //Mulheres Sadias
    for(unsigned i =0; i < __m_sadias; i++)
    {
        
        std::string nome = "Maria Malafaia";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(false,false);

        //cidadao = new Mulher(nome,idade,saude);
        Mulher *cidada = new Mulher(nome, idade, saude);
        addPessoa(cidada);
    }

    
    //Mulheres Infectadas
    for(unsigned i =0; i < __m_infectadas; i++)
    {
        std::string nome = "Creusa Edineia";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(true,false,data);

        Mulher *cidada = new Mulher(nome, idade, saude);
        addPessoa(cidada);
    }

    //Homens Sadios
    for(unsigned i =0; i < __h_sadios; i++)
    {
        std::string nome = "Joao Augusto";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(false,false);

        Homem *cidadao = new Homem(nome, idade, saude);
        addPessoa(cidadao);
    }

    //Homens Infectados
    for(unsigned i =0; i < __h_infectados; i++)
    {
        std::string nome = "Robson Quebradeira";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(true,false,data);

        Homem *cidadao = new Homem(nome, idade, saude);
        addPessoa(cidadao);
    }
    
}
Cep Cidade::gerarCep()
{
    srand(time(NULL));

    Cep endereco;
    unsigned line,column;

    if(populacao_size == 100)    return endereco;

    do{
        line = unsigned(rand() %10);
        column = unsigned(rand() %10);
    }while(mapa[line][column] != NULL);
    
    endereco.x = line;
    endereco.y = column;
    return endereco;
}


void Cidade::projecao(unsigned &anos)
{
    while(anos > 0)
    {
        rotinas();
        anos--;
    }
    std::cout << "Mulheres Sadias: " << n_mulheres_sadias() << std::endl
              << "Mulheres Infectadas: " << n_mulheres_infectadas() << std::endl
              << "Homens Sadios: " << n_homens_sadios() << std::endl
              << "Homens Infectados: " << n_homens_infectados() << std::endl
              << "Populacao Total: " << populacao_size 
              << " Sadias: " << n_pessoas_sadias()
              << " Infectadas: " << n_pessoas_infectadas() << std::endl;

    print();

}

void Cidade::rotinas()
{


    data.setAno(data.getAno()+1);

    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {
            //Incentivar Reproducao
            if(mapa[line][column] != NULL)
            {
                Cep cep_cidadao;
                cep_cidadao.x = line;
                cep_cidadao.y = column;

                if(typeid((*mapa[cep_cidadao.x][cep_cidadao.y ])) == typeid(Mulher))
                {
                    incentivarReproducao(cep_cidadao);
                }
                

                //Vacinar Populacao
                mapa[line][column]->vacinar();

                //Checar Contaminacao
                checarContaminacao(cep_cidadao);

                //Envelhecer Cidadaos
                mapa[line][column]->setIdade(mapa[line][column]->getIdade()+1);

                //Verificar Obitos
                if(mapa[line][column]->morrer(data))
                {
                    cout << "Morreu com: " << mapa[line][column]->getIdade() << endl;
                    delete mapa[line][column];
                    mapa[line][column] = NULL;
                    populacao_size--;
                }
            }
        }
    }

    //Realocar Populacao
    realocarPopulacao();

}

bool Cidade::incentivarReproducao(Cep pos)
{
    Cep amante;
    amante.x = pos.x;
    amante.y = pos.y;
    Pessoa *bebe = NULL;
    if(amante.x +1 < N_LINHAS && mapa[amante.x+1][amante.y] != NULL)
    {
        bebe = mapa[pos.x][pos.y]->engravidar(mapa[amante.x+1][amante.y]);

    }else if(int(amante.x -1) >= 0 && mapa[amante.x-1][amante.y] != NULL)
    {
        bebe = mapa[pos.x][pos.y]->engravidar(mapa[amante.x-1][amante.y]);

    }else if(amante.y +1 < N_COLUNAS && mapa[amante.x][amante.y+1] != NULL)
    {
        bebe = mapa[pos.x][pos.y]->engravidar(mapa[amante.x][amante.y+1]);

    }else if(int(amante.y -1) >= 0 && mapa[amante.x][amante.y-1] != NULL)
    {
        bebe = mapa[pos.x][pos.y]->engravidar(mapa[amante.x][amante.y-1]);
    }
    addPessoa(bebe);
    return (bebe != NULL);
}

 bool Cidade::checarContaminacao(Cep pos)
 {
    Cep infectado;
    infectado.x = pos.x;
    infectado.y = pos.y;
    Saude saude = Saude(true,false,data);

    if(mapa[pos.x][pos.y]->vuneravel()){
        if(infectado.x +1 < N_LINHAS && mapa[infectado.x+1][infectado.y] != NULL)
        {
            if(mapa[infectado.x+1][infectado.y]->getSaude().getDoente())
            {
                mapa[pos.x][pos.y]->setSaude(saude);
                cout << "Infectado: " << mapa[pos.x][pos.y]->getIdade() << endl;
                return true;
            }
        }if(int(infectado.x -1) >= 0 && mapa[infectado.x-1][infectado.y] != NULL)
        {
            if(mapa[infectado.x-1][infectado.y]->getSaude().getDoente())
            {
                mapa[pos.x][pos.y]->setSaude(saude);
                cout << "Infectado: " << mapa[pos.x][pos.y]->getIdade() << endl;
                return true;
            }
        }if(infectado.y +1 < N_COLUNAS && mapa[infectado.x][infectado.y+1] != NULL)
        {
            if(mapa[infectado.x][infectado.y+1]->getSaude().getDoente())
            {
                mapa[pos.x][pos.y]->setSaude(saude);
                cout << "Infectado: " << mapa[pos.x][pos.y]->getIdade() << endl;
                return true;
            }
        }if(int(infectado.y -1) >= 0 && mapa[infectado.x][infectado.y-1] != NULL)
        {
            if(mapa[infectado.x][infectado.y-1]->getSaude().getDoente())
            {
                mapa[pos.x][pos.y]->setSaude(saude);
                cout << "Infectado: " << mapa[pos.x][pos.y]->getIdade() << endl;
                return true;
            }
        }
    }
    return false;
 }

void Cidade::realocarPopulacao()
{
    Cep origem;
    origem.x = 0; origem.y = 0;
    Cep destino;

    Pessoa *last = mapa[N_LINHAS-1][N_COLUNAS-1];

    do{

        destino.x = origem.x;
        destino.y = origem.y;

        origem.y = (origem.y +1) %N_COLUNAS;
        origem.x = (destino.y == (N_COLUNAS -1)) ? (origem.x +1) %N_LINHAS : origem.x;

        mapa[(N_LINHAS -1)- destino.x][(N_COLUNAS -1)- destino.y] = mapa[(N_LINHAS -1)- origem.x][(N_COLUNAS -1)- origem.y];

    }while(origem.x || origem.y);
    
    mapa[0][0] = last;
}


unsigned Cidade::n_mulheres_sadias()
{
    unsigned occurrences = 0;
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {   
            if(mapa[line][column] != NULL && typeid(*mapa[line][column]) == typeid(Mulher)){
                occurrences += !(mapa[line][column]->getSaude().getDoente()) ? 1 : 0;
            }
        }
    }
    return occurrences;
}

unsigned Cidade::n_mulheres_infectadas()
{
    unsigned occurrences = 0;
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {
            if(mapa[line][column] != NULL && typeid(*mapa[line][column]) == typeid(Mulher)){
                occurrences += (mapa[line][column]->getSaude().getDoente()) ? 1 : 0;
            }
        }
    }
    return occurrences;    
}

unsigned Cidade::n_homens_sadios()
{
    unsigned occurrences = 0;
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {
            if(mapa[line][column] != NULL && typeid(*mapa[line][column]) == typeid(Homem))
                occurrences += !(mapa[line][column]->getSaude().getDoente()) ? 1 : 0;
        }
    }
    return occurrences;
}

unsigned Cidade::n_homens_infectados()
{
    unsigned occurrences = 0;
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {
            if(mapa[line][column] != NULL && typeid(*mapa[line][column]) == typeid(Homem))
                occurrences += (mapa[line][column]->getSaude().getDoente()) ? 1 : 0;
        }
    }
    return occurrences;
}

unsigned Cidade::n_pessoas_sadias()
{
    return n_mulheres_sadias() + n_homens_sadios();
}

unsigned Cidade::n_pessoas_infectadas()
{
    return n_mulheres_infectadas() + n_homens_infectados();
}

void Cidade::print()
{
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {   
            if(mapa[line][column] != NULL)
                cout << "{" << (*mapa[line][column]).toPrettyLine() << "} ";
            else 
                cout << "{" << "[.][.][.][.]" << "} ";
        }
        cout << endl;
    }
}



Cidade::Cidade()
{

}

Cidade::Cidade(const Cidade &__cidade)
{
    data = __cidade.data;
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {
            mapa[line][column] = __cidade.mapa[line][column];
        }
    }    
}

Cidade::Cidade(Data &__data)
{
    data = __data;

    populacao_size = 0;

    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {   
            mapa[line][column] = NULL;
        }
    }      
}

void Cidade::setData(Data &__data)
{
    data = __data;
}