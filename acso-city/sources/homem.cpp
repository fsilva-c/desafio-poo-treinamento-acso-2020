#include "homem.hpp"
#include <string>

std::string Homem::toPrettyLine()
{
    return "[H]" + Pessoa::toPrettyLine();
}

Homem::Homem()
{

}
Homem::Homem(const Homem &__homem) : 
Pessoa(__homem.nome, __homem.idade, __homem.saude)
{

}
Homem::Homem(std::string __nome, unsigned __idade, Saude __saude) :
Pessoa(__nome,__idade,__saude)
{

}