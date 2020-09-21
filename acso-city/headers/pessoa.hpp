#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

#include "saude.hpp"
#include <string>

class Pessoa
{
    protected :
        std::string nome;
        unsigned idade;
        Saude saude;

    public :
        bool morrer(Data &__data);
        bool vacinar();
        std::string toPrettyLine(); 

        virtual Pessoa* engravidar(Pessoa &amante);

        Pessoa();
        Pessoa(const Pessoa &__pessoa);
        Pessoa(std::string __nome, unsigned __idade, Saude __saude);

        virtual ~Pessoa();

        void setIdade(const unsigned &__idade);
        void setSaude(const Saude &__saude);
        std::string getNome();
        unsigned getIdade();
        Saude getSaude();


};

#endif