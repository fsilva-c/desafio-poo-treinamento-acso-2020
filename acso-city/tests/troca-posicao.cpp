#include <iostream>

using namespace std;

#define MAX 10

/* g++ -o troca-posicao.o troca-posicao.cpp && ./troca-posicao.o */

int main(){
    unsigned short vet[MAX] = {6, 3, 7, 3, 0, 77, 2, 3, 7, 4}, ultimo = vet[MAX - 1]; 
    unsigned short array[MAX] = {1, 1, 0, 0, 0, 0};

    unsigned short count = 0;
    for(size_t i = 0; i < 6; i++){
        if(array[i] != 0){
            unsigned short j = i;
            while(array[j] != 0){
                j++;
                count++;
            }
            
        }
    }

    cout << count << endl;

}//END main