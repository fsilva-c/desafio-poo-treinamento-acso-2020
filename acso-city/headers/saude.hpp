#ifndef _SAUDE_HPP_
#define _SAUDE_HPP_

#include "data.hpp"

class Saude
{
    private :
        bool doente;
        bool vacinado;
        Data data;

    public:
        bool infectar(Data &__data);

        Saude();
        Saude(const Saude &__saude);
        Saude(bool __doente, bool __vacinado, Data __data = Data());
        
        void setDoente(bool __doente);
        void setVacinado(bool __vacinado);
        void setData(bool __data);
        bool getDoente();
        bool getVacinado();
        Data getData();

};

#endif