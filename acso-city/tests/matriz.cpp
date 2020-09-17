#include <iostream>
#include <time.h> 

using namespace std;

#define L_MATRIZ 10
#define C_MATRIZ 10

enum TpPessoas{ hSaudavel = 1, mSaudavel, hInfectado, mInfectada, hVacinado, mVacinada };

void incializarMatriz(unsigned short matrix[][C_MATRIZ]);
void exibirMatriz(unsigned short matrix[][C_MATRIZ]);
void popularMatriz(unsigned short matrix[][C_MATRIZ], unsigned short qnt, unsigned short tpPessoa);
unsigned short gerarPosMatriz();
bool checkPosMatrizVazia(unsigned short matrix[][C_MATRIZ], unsigned short lMatrix, unsigned short cMatrix);
unsigned short qntHabitantes(unsigned short matrix[][C_MATRIZ]);


int main(){
    srand(time(NULL));

    unsigned short city[L_MATRIZ][C_MATRIZ];
    
    incializarMatriz(city);

    popularMatriz(city, 1, mInfectada);
    popularMatriz(city, 10, mSaudavel);
    popularMatriz(city, 1, hInfectado);
    popularMatriz(city, 10, hSaudavel);

    exibirMatriz(city);
    printf("Qnt Hab = %d\n", qntHabitantes(city));
    

    return 0;
}//END main


void incializarMatriz(unsigned short matrix[][C_MATRIZ]){
    for(size_t i = 0; i < L_MATRIZ; i++)
        for(size_t j = 0; j < C_MATRIZ; j++)
            matrix[i][j] = 0;
}//END function

void exibirMatriz(unsigned short matrix[][C_MATRIZ]){
    for(size_t i = 0; i < L_MATRIZ; i++){
        for(size_t j = 0; j < C_MATRIZ; j++)
            cout << matrix[i][j] << " " ;

        cout << endl;
    }
}//END function

void popularMatriz(unsigned short matrix[][C_MATRIZ], unsigned short qnt, unsigned short tpPessoa){
    unsigned short lMatriz, cMatriz;

    size_t i = 0;
    while(i < qnt){
        if(checkPosMatrizVazia(matrix, lMatriz, cMatriz)){
            matrix[lMatriz][cMatriz] = tpPessoa;

            i++;
        }
        lMatriz = gerarPosMatriz(), cMatriz = gerarPosMatriz();
    }
}//END function

unsigned short gerarPosMatriz(){ 
    return rand() % 10;
}//END function

bool checkPosMatrizVazia(unsigned short matrix[][C_MATRIZ], unsigned short lMatrix, unsigned short cMatrix){
    if(matrix[lMatrix][cMatrix] == 0) return true;
    else return false;
}//END function

unsigned short qntHabitantes(unsigned short matrix[][C_MATRIZ]){
    unsigned short qntHab = 0;

    for(size_t i = 0; i < L_MATRIZ; i++)
        for(size_t j = 0; j < C_MATRIZ; j++)
            if(matrix[i][j] != 0)
                qntHab++;

    return qntHab;
}//END function