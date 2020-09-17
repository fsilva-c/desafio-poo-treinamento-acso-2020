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
void passarUmAno(unsigned short matrix[][C_MATRIZ]);


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
    
    //passarUmAno(city);

    //exibirMatriz(city);

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

void passarUmAno(unsigned short matrix[][C_MATRIZ]){
    CursorMatriz cursor; cursor.linha = 0; cursor.coluna = 0;
    CursorMatriz aux;

    for(size_t i = 0; i < qntHabitantes(matrix); ){
        
        for(size_t j = 0; j < L_MATRIZ; j++)
            for(size_t k = 0; k < C_MATRIZ; k++){
                if(matrix[cursor.linha][cursor.coluna] != 0){
                 aux.linha = cursor.linha; aux.coluna = cursor.coluna;
                    while(matrix[aux.linha][aux.coluna] != 0){
                        //aux.linha++;
                        aux.coluna++;
                        if(aux.coluna > C_MATRIZ){ 
                            aux.coluna = 0; 
                            aux.linha++;
                            if(aux.linha > L_MATRIZ) aux.linha = 0;
                        }

                    }
                    i++;
                }
            }


        cout << aux.linha << " " << aux.coluna << endl;
        for(size_t o = aux.coluna; o > 0; o--)
            matrix[aux.linha][aux.coluna] = matrix[aux.linha][aux.coluna - 1];
    }
}//END function