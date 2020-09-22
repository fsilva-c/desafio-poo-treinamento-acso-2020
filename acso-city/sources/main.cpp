#include <ostream>

#include "cidade.hpp"
#include "mulher.hpp"

using std :: cout;
using std :: string;
using std :: cin;

int main(){
    Data date0(1, 1, 2000);
    Data date1(30, 4, 2001);
    Data date2(31, 1, 2000);
    Data date3(12, 11, 2000);

    Cidade acso_city(date0);

    unsigned m_sadias,m_infectadas,h_sadios,h_infectados,ano;
    cout << "N Mulheres Sadias: "; cin >> m_sadias;
    cout << "N Mulheres Infectadas: "; cin >> m_infectadas;
    cout << "N Homens Sadios: "; cin >> h_sadios;
    cout << "N Homens Infectados: "; cin >> h_infectados;

    acso_city.popular(m_sadias,m_infectadas,h_sadios,h_infectados);

    cout << "Tempo para projecao: ";cin >> ano;
    acso_city.print();
    acso_city.projecao(ano);

   
}//END main