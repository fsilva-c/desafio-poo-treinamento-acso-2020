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
    
    passarUmAno(city);
    exibirMatriz(city);

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
    /* IMCOMPLETA */
    
    CursorMatriz aux;

    //for(size_t i = 0; i < qntHabitantes(matrix); ){
        
        for(size_t j = 0; j < L_MATRIZ; j++){
            for(size_t k = 0; k < C_MATRIZ; k++){
                if(matrix[j][k] != 0)
                    cout << j << " " << k << endl;
            }
        }
    //}
}//END function

//Implementação prototipo de função para permutar membros da matriz
void realocarPopulacao()
{
    struct Cep
    {
        unsigned x;
        unsigned y;
    };
    
    char *mapa[10][10];
    unsigned N_LINHAS = 10;
    unsigned N_COLUNAS = 10;
    //busca por endereço vazio
    Cep destino; //= gerarCep();
    for(unsigned line=0; line < N_LINHAS; line++)
    {
        for(unsigned column = 0; column < N_COLUNAS; column++)
        {
            if(mapa[line][column] != NULL)
            {
                destino.x = line;
                destino.y = column;
            }
        }
    }
    
    Cep base = destino;
    do{
        unsigned line = base.x;
        unsigned column = base.y;

        base.y = (base.y +1) %10;
        base.x = !(base.y) ? (base.x +1) %10 : base.x;


    }while(base.x != destino.x && base.y != destino.y);
    
}
