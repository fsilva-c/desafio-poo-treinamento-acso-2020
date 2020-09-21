#include "../headers/pessoa.hpp"
#include <string>
#include <ostream>

void Pessoa::morrer(Data &__data)
{
    if(idade >= 30 || (saude.getData().datacrp(__data) >= -730 && saude.getDoente()))
    {
        std::cout << "Objeto destruido";
        //Pessoa::~Pessoa(); chamada destrutor...
       
    }
}

bool Pessoa::vacinar()
{
    if((idade <= 8 && idade >= 3) && !(saude.getDoente()))
    {
        saude.setVacinado(true);
        return true;
    }
    return false;
}

std::string Pessoa::toPrettyLine()
{
    return '[' + std::to_string(idade) + "][" + (saude.getDoente() ? 'I' : 'S') + "][" + (saude.getVacinado() ? 'V' : 'N') + ']';
}

Pessoa::Pessoa()
{

}
Pessoa::Pessoa(const Pessoa &__pessoa)
{
    nome = __pessoa.nome;
    idade = __pessoa.idade;
    saude = __pessoa.saude;
}
Pessoa::Pessoa(std::string __nome, unsigned __idade, Saude __saude)
{
    nome = __nome;
    idade = __idade;
    saude = __saude;
}

void Pessoa::setIdade(const unsigned &__idade)
{
    idade = __idade;
}
void Pessoa::setSaude(const Saude &__saude)
{
    saude = __saude;
}
std::string Pessoa::getNome()
{
    return nome;
}
unsigned Pessoa::getIdade()
{
    return idade;
}
Saude Pessoa::getSaude()
{
    return saude;
}
