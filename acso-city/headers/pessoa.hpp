#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

#include "saude.hpp"
#include <string>

class Pessoa
{
    private :
        string nome;
        unsigned idade;
        Saude saude;

    public :
        bool morrer(Data &__data);

        Pessoa();
        Pessoa(const Pessoa &__pessoa);
        Pessoa(string &__nome, unsigned &__idade, Saude &__saude);


};

#endif