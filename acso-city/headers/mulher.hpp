#ifndef _MULHER_HPP_
#define _MULHER_HPP_

#include "pessoa.hpp"
#include <string>

class Mulher: public Pessoa
{
    private :
        bool gestacao;

    public :
        Pessoa* engravidar(Pessoa *amante);
        std::string toPrettyLine();

        Mulher();
        Mulher(const Mulher &__mulher);
        Mulher(string __nome, unsigned __idade, Saude __saude, bool __gestacao=false);

        bool getGestacao();

};

#endif