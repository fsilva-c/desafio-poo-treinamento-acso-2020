#ifndef _CIDADE_HPP_
#define _CIDADE_HPP_

#include "data.hpp"
#include "pessoa.hpp"
#include "mulher.hpp"
#include "homem.hpp"

#define N_LINHAS 10
#define N_COLUNAS 10

typedef struct Cep
{
    unsigned x;
    unsigned y;
}Cep;

class Cidade
{
    private:
        unsigned populacao_size;
        Pessoa *mapa[N_LINHAS][N_COLUNAS];
        Data data;

    public:
        bool addPessoa(Pessoa *__pessoa);
        void popular(unsigned &__m_sadias, unsigned &__m_infectadas, unsigned &__h_sadios, unsigned &__h_infectados);
        Cep gerarCep();

        void projecao(unsigned &anos);
        void rotinas();

        unsigned n_mulheres_sadias();
        unsigned n_mulheres_infectadas();
        unsigned n_homens_sadios();
        unsigned n_homens_infectados();
        unsigned n_pessoas_sadias();
        unsigned n_pessoas_infectadas();

        void print();

        Cidade();
        Cidade(const Cidade &__cidade);
        Cidade(Data &__data);

        void setData(Data &__data);

};

#endif