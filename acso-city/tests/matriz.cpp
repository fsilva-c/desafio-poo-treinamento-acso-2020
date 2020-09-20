#include <iostream>
#include <time.h> 

using namespace std;

#define L_MATRIZ 10
#define C_MATRIZ 10

enum TpPessoas{ hSaudavel = 1, mSaudavel, hInfectado, mInfectada, hVacinado, mVacinada };

typedef struct cursor{
    unsigned short linha, coluna;
}CursorMatriz;

void incializarMatriz(unsigned short matrix[][C_MATRIZ]);
void exibirMatriz(unsigned short matrix[][C_MATRIZ]);
void popularMatriz(unsigned short matrix[][C_MATRIZ], unsigned short qnt, unsigned short tpPessoa);
unsigned short gerarPosMatriz();
bool checkPosMatrizVazia(unsigned short matrix[][C_MATRIZ], unsigned short lMatrix, unsigned short cMatrix);
unsigned short qntHabitantes(unsigned short matrix[][C_MATRIZ]);
void passarUmAno(unsigned short matrix[][C_MATRIZ], unsigned short l, unsigned short c);

/* g++ -o matriz.o matriz.cpp && ./matriz.o */ 

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
    passarUmAno(city, 0, 0);

    exibirMatriz(city);
    printf("Qnt Hab = %d\n", qntHabitantes(city));

    return 0;
}//END main


void incializarMatriz(unsigned short matrix[][C_MATRIZ]){
    /* Esta função inicializa a matriz com todos os índices zerados */

    for(size_t i = 0; i < L_MATRIZ; i++)
        for(size_t j = 0; j < C_MATRIZ; j++)
            matrix[i][j] = 0;
}//END function

void exibirMatriz(unsigned short matrix[][C_MATRIZ]){
    /* Esta função percorre a matriz exibindo os valores armazenados em cada índice */

    for(size_t i = 0; i < L_MATRIZ; i++){
        for(size_t j = 0; j < C_MATRIZ; j++)
            cout << matrix[i][j] << " " ;

        cout << endl;
    }
}//END function

void popularMatriz(unsigned short matrix[][C_MATRIZ], unsigned short qnt, unsigned short tpPessoa){
    /* Esta função popula a matriz a partir do tipo da pessoa e a quantidade que irá ser inserida na matrix */

    unsigned short lMatriz, cMatriz;

    for(size_t i = 0; i < qnt; ){
        lMatriz = gerarPosMatriz(), cMatriz = gerarPosMatriz();

        if(checkPosMatrizVazia(matrix, lMatriz, cMatriz)){
            matrix[lMatriz][cMatriz] = tpPessoa;

            i++;
        }
    }
}//END function

unsigned short gerarPosMatriz(){ 
    /* Esta função gera um número aleatório entre 0 e 9 */
    return rand() % 10;
}//END function

bool checkPosMatrizVazia(unsigned short matrix[][C_MATRIZ], unsigned short lMatrix, unsigned short cMatrix){
    /* Esta função avalia se a matriz, no índice passado está por parâmetro, está com o valor zerado */

    if(matrix[lMatrix][cMatrix] == 0) return true;
    else return false;
}//END function

unsigned short qntHabitantes(unsigned short matrix[][C_MATRIZ]){
    /* Esta função percorre a matriz e retorna a quantidade de habitantes na matriz */

    unsigned short qntHab = 0;

    for(size_t i = 0; i < L_MATRIZ; i++)
        for(size_t j = 0; j < C_MATRIZ; j++)
            if(matrix[i][j] != 0)
                qntHab++;

    return qntHab;
}//END function

void passarUmAno(unsigned short matrix[][C_MATRIZ], unsigned short l, unsigned short c){
    //percorreu toma matriz
    if((l == L_MATRIZ - 1) && (c == C_MATRIZ - 1)) return;

    c++;
    if(c == C_MATRIZ - 1){
        c = 0;
        l++;
        if(l == L_MATRIZ -1)
            l++;
    }

    matrix[l][c + 1] = matrix[l][c];
    passarUmAno(matrix, l, c);
}

/*
void passarUmAno(unsigned short matrix[][C_MATRIZ]){
    //IMCOMPLETA
    
    CursorMatriz aux;
    unsigned short matrixAux[L_MATRIZ][C_MATRIZ]; incializarMatriz(matrixAux);

    //for(size_t i = 0; i < qntHabitantes(matrix); ){
        
    for(size_t i = 0; i < L_MATRIZ; i++){
        for(size_t j = 0; j < C_MATRIZ; j++){
            if((matrix[i][j] != 0) && (matrix[i][j + 1] == 0) && (j != C_MATRIZ - 1)){
                //valor com espaço ao lado
                //cout << i << " " << j << endl;
                matrixAux[i][j + 1] = matrix[i][j];
            }
            else if((matrix[L_MATRIZ - 1][C_MATRIZ - 1] != 0) && (matrix[0][0] == 0)){
                //valor da ponta [0][0]
                matrixAux[0][0] = matrix[L_MATRIZ - 1][C_MATRIZ - 1];
            }
            else if(((j == C_MATRIZ - 1) && (matrix[i][C_MATRIZ - 1] != 0)) || ((matrix[i][j] != 0) && (matrix[i][j + 1] != 0))){
                //caso número na coluna - 1 e números alocados consecultivamente
                //printf("[%zu] [%zu]\n", i, j);
                aux.linha = i; aux.coluna = j;
                while(matrix[aux.linha][aux.coluna] != 0){
                    aux.coluna++;
                    if(aux.coluna == C_MATRIZ - 1){
                        aux.coluna = 0;
                        aux.linha++;
                        if(aux.linha == L_MATRIZ - 1)
                            aux.linha = 0;
                    }
                }
                
                for(size_t a = aux.coluna; a > 0; a--){
                    matrixAux[aux.linha][a] = matrixAux[aux.linha][a - 1];
                    if(matrix[aux.linha][a] == 0) break;
                }
                printf("{%i} {%i}\n", aux.linha, aux.coluna);
            }
        }
    }

    exibirMatriz(matrixAux);
    printf("Qnt Hab = %d\n", qntHabitantes(matrixAux));
    //}
}//END function
*/

/*
    if(coluna >= C_MATRIZ){
        coluna = 0;
        linha++;
        if(linha >= L_MATRIZ) linha = 0;
    }
*/