#include "../headers/cidade.hpp"
#include "../headers/saude.hpp"
#include "../headers/pessoa.hpp"
#include "../headers/mulher.hpp"
#include "../headers/homem.hpp"
#include <ostream>
#include <string>
#include <typeinfo>

bool Cidade::addPessoa(Pessoa &__pessoa)
{
    if(populacao_size == 40)    return false;

    Cep endereco = gerarCep();
    mapa[endereco.x][endereco.y] = &__pessoa;
    populacao_size++;
    return true;
}

void Cidade::popular(unsigned &__m_sadias, unsigned &__m_infectadas, unsigned &__h_sadios, unsigned &__h_infectados)
{
    Pessoa *cidadao;
    //Mulheres Sadias
    for(unsigned i =0; i < __m_sadias; i++)
    {
        std::string nome = "Maria";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(false,false);

        cidadao = new Mulher(nome,idade,saude);
        addPessoa(*cidadao);
    }

    //Mulheres Infectadas
    for(unsigned i =0; i < __m_infectadas; i++)
    {
        std::string nome = "Creusa";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(true,false,data);

        cidadao = new Mulher(nome,idade,saude); 
        addPessoa(*cidadao); 
    }

    //Homens Sadios
    for(unsigned i =0; i < __h_sadios; i++)
    {
        std::string nome = "Joao";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(false,false);

        cidadao = new Homem(nome,idade,saude);
        addPessoa(*cidadao);
    }

    //Homens Infectados
    for(unsigned i =0; i < __h_infectados; i++)
    {
        std::string nome = "Robson";
        unsigned idade = unsigned(rand() %20);
        Saude saude = Saude(true,false,data);

        cidadao = new Mulher(nome,idade,saude);
        addPessoa(*cidadao);
    }
}
Cep Cidade::gerarCep()
{
    Cep endereco;
    unsigned line,column;

    if(populacao_size == 40)    return endereco;

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
        << " Sadias: " << n_pessoas_sadias
        << " Infectadas: " << n_pessoas_infectadas << std::endl;

    print();

}

void Cidade::rotinas()
{
    //Incentivar Reproducao

    //Vacinar Populacao

    //Verificar Obitos

    //Checar Contaminacao

    //Avancar Enderecos

    //Envelhecer Cidadaos
}



unsigned Cidade::n_mulheres_sadias()
{
    unsigned occurrences = 0;
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column=0; column < N_COLUNAS; column++)
        {
            Pessoa habitante = (*mapa[line][column]);
            occurrences +=  (typeid(habitante) == typeid(Mulher) && !(habitante.getSaude().getDoente())) ? 1 : 0;
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
            Pessoa habitante = (*mapa[line][column]);
            occurrences +=  (typeid(habitante) == typeid(Mulher) && habitante.getSaude().getDoente()) ? 1 : 0;
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
            Pessoa habitante =(*mapa[line][column]);
            occurrences +=  (typeid(habitante) == typeid(Homem) && !(habitante.getSaude().getDoente())) ? 1 : 0;
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
            Pessoa habitante = (*mapa[line][column]);
            occurrences +=  (typeid(habitante) == typeid(Homem) && habitante.getSaude().getDoente()) ? 1 : 0;
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
           cout << "{" << (*mapa[line][column]).toPrettyLine() << "}"; 
        }
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