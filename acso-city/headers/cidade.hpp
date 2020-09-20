#ifndef _CIDADE_HPP_
#define _CIDADE_HPP_

#include "data.hpp"
#include "pessoa.hpp"

#define N_LINHAS 10
#define N_COLUNAS 10

class Cidade
{
    private:
        Pessoa mapa[N_LINHAS][N_COLUNAS];
        Data data;

    public:
        bool vacinar(Pessoa &__pessoa);

        Cidade();
        Cidade(const Cidade &__cidade);
        Cidade(Data &__data);

};


#endif