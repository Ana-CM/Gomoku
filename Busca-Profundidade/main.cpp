
#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <stack>
#include <list>
using namespace std;

// Regras
// preta sempre começa
// as jogas serão feitas de formas alternadas entre as peças pretas e brancas.
// só poderá ser posicionada um peça em casa do tabuleiro que não esteja sendo ocupada por outra peça.
// o jogo termina quando quando em tiver quatro peças consecutivas de cor preta.


bool ganhou( int tabuleiro ) {

}

bool perdeu( int tabuleiro ) {

}

vector int filhos( int tabuleiro ) {

}

int jogar_branco( int tabuleiro ) {

}

void imprime_caminho( ) {

}

int main() {

    const int num = 4;
    int tabuleiro[num][num] = {0};
    vector int visitados;
    stack<int> aberto;
    list<int> fechado;

    while( true ) {

        if ( ganhou( tabuleiro ) ) {
            break;
        }

        aberto.push( filhos( tabuleiro ) );
        fechado.push_back( tabuleiro);

        tabuleiro = aberto.pop(); 




    }
    
    return 0;
}