#ifndef _HOMEM_HPP_
#define _HOMEM_HPP_

#include "pessoa.hpp"
#include <string>

class Homem : public Pessoa
{
    private :

    public :
        
        Homem();
        Homem(const Homem &__homem);
        Homem(std::string __nome, unsigned __idade, Saude __saude);

};

#endif