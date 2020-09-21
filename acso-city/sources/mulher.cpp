#include "../headers/mulher.hpp"
#include "../headers/homem.hpp"
#include "../headers/saude.hpp"
#include <typeinfo>
#include <string>

Pessoa* Mulher::engravidar(Pessoa &amante)
{
    Pessoa *bebe = NULL;
    if(!(gestacao) && (typeid(Homem) == typeid(amante)) && (idade <= 25 && idade >= 18) && (amante.getIdade() <= 25 && amante.getIdade() >= 18) )
    {
        std::cout << "In Love S2 !";

        if(idade >= amante.getIdade())
        {
            std::string bebe_nome = nome.substr(0,5) + amante.getNome().substr(5,10);
            bebe = new Mulher(bebe_nome,0,Saude(false,false));

        }else{
            std::string bebe_nome = amante.getNome().substr(0,5) + nome.substr(0,5);
            bebe = new Homem(bebe_nome,0,Saude(false,false)); 
        } 
    }
    gestacao = !gestacao;
    return bebe;
}

std::string Mulher::toPrettyLine()
{
    return "[M]" + Pessoa::toPrettyLine();
} 

Mulher::Mulher()
{

}

Mulher::Mulher(const Mulher &__mulher) :
Pessoa(__mulher.nome,__mulher.idade,__mulher.saude)
{
    gestacao = __mulher.gestacao;
}

Mulher::Mulher(string __nome, unsigned __idade, Saude __saude, bool __gestacao=false) :
Pessoa(__nome,__idade,__saude)
{
    gestacao = __gestacao;
}


bool Mulher::getGestacao()
{
    return gestacao;
}
