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
        void emGestacao();
        std::string toPrettyLine();

        Mulher();
        Mulher(const Mulher &__mulher);
        Mulher(string __nome, unsigned __idade, Saude __saude, bool = false);

        bool getGestacao();
        void setGestacao(bool __gestacao);

};

#endif