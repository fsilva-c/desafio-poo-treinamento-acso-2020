#include "data.hpp"

using namespace std;

Data::Data(){}
Data::Data(const Data &__data)
{
    dia = __data.dia;
    mes = __data.mes;
    ano = __data.ano;
}
Data::Data(unsigned long data)
{
    dia = data /1000000;
    mes = (data /10000)%100;
    ano = data %10000;
}
Data::Data(unsigned __dia, unsigned __mes, unsigned __ano)
{
    dia = __dia;
    mes = __mes;
    ano = __ano;
}
int Data::datacrp(Data data)
{
    int crp = 0;
    crp = dia - data.getDia();
    crp += mes *30 - data.getMes() *30;
    crp += ano *365 - data.getAno() *365;
    return crp;
}
void Data::printData()
{
    cout << dia 
        << "/" << mes 
        << "/" << ano << endl;
}

ostream& operator<<(ostream &os, const Data &data){
    os << data.dia << '/' << data.mes << '/' << data.ano;
    return os;
}

void Data::setDia(unsigned __dia)
{
    dia = __dia;
}
void Data::setMes(unsigned __mes)
{
    mes = __mes;
}
void Data::setAno(unsigned __ano)
{
    ano = __ano;
}
unsigned Data::getDia()
{
    return dia;
}
unsigned Data::getMes()
{
    return mes;
}
unsigned Data::getAno()
{
    return ano;
}