#include "../headers/saude.hpp"

bool Saude::infectar(Data &__data)
{
    if(vacinado)    return false;

    data = __data;
    doente = true;
    return true;
}

Saude::Saude()
{

}
Saude::Saude(const Saude &__saude)
{
    doente = __saude.doente;
    vacinado = __saude.vacinado;
    data = __saude.data;
}
Saude::Saude(bool __doente, bool __vacinado, Data __data)
{
    doente = __doente;
    vacinado = __vacinado;
    data = __data;
}

void Saude::setDoente(bool __doente)
{
    doente = __doente;
}
void Saude::setVacinado(bool __vacinado)
{
    vacinado = __vacinado;
}
void Saude::setData(bool __data)
{
    data = __data;
}
bool Saude::getDoente()
{
    return doente;
}
bool Saude::getVacinado()
{
    return vacinado;
}
Data Saude::getData()
{
    return data;
}