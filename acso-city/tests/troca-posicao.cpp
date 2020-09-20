#include <iostream>

using namespace std;

#define MAX 10

/* g++ -o troca-posicao.o troca-posicao.cpp && ./troca-posicao.o */

int main(){
    unsigned short vet[MAX] = {6, 3, 7, 3, 0, 77, 2, 3, 0, 0};

    for(size_t i = MAX - 1; i > 0; i--)
        vet[i] = vet[i - 1];

    for(size_t i = 0; i < MAX; i++)
        cout << vet[i] << " ";

    cout << endl;
}//END main