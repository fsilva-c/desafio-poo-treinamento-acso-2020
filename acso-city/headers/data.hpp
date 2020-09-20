#ifndef _DATA_HPP_
#define _DATA_HPP_

#include <iostream>
using namespace std;

class Data
{
    private:
        unsigned dia;
        unsigned mes;
        unsigned ano;

    public:
        Data();
        Data(const Data &__questao);
        Data(unsigned long data);
        Data(unsigned __dia, unsigned __mes, unsigned __ano);
        int datacrp(Data data);
        void printData();

        friend ostream& operator<<(ostream &os, const Data &data);

        void setDia(unsigned __dia);
        void setMes(unsigned __mes);
        void setAno(unsigned __ano);
        unsigned getDia();
        unsigned getMes();
        unsigned getAno();
};

#endif