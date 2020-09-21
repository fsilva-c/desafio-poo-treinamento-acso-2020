#include <ostream>

#include "cidade.hpp"
#include "mulher.hpp"

using std :: cout;
using std :: string;

int main(){
    Data date0(1, 1, 2000);
    Data date1(30, 4, 2001);
    Data date2(31, 1, 2000);
    Data date3(12, 11, 2000);

    Cidade acso_city(date0);

    unsigned a = 10, b = 1;
    unsigned &pop_1 = a, &pop_2 = b;
    acso_city.popular(pop_1, pop_2, pop_1, pop_2);

    cout << acso_city.n_mulheres_sadias() << endl;

    acso_city.print();
}//END main