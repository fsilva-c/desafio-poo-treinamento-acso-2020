#ifndef _HOMEM_HPP_
#define _HOMEM_HPP_

#include "pessoa.hpp"

class Homem : public Pessoa
{
    private :

    public :
        
        Homem();
        Homem(const Homem &__homem);
        Homem(string &__nome, unsigned &__idade, Saude &__saude);

};

#endif