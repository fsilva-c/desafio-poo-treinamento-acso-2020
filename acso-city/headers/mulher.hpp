#ifndef _MULHER_HPP_
#define _MULHER_HPP_

#include "pessoa.hpp"

class Mulher: public Pessoa
{
    private :
        bool gestacao;

    public :

        Mulher();
        Mulher(const Mulher &__mulher);
        Mulher(string &__nome, unsigned &__idade, Saude &__saude, bool &__gestacao);

        Pessoa engravidar(Pessoa &amante);

};

#endif