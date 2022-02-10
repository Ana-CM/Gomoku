#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "./Grafo/Grafo.h"
#include "./Grafo/No.h"
#include "Tabuleiro.cpp"

using namespace std;

int main()
{
    Grafo *gomoku = new Grafo();
    No *raiz = gomoku->getRaiz();
    cout << raiz->getTabuleiro() << endl;
    raiz->getTabuleiro()->fazerJogada(0,0,1);
    raiz->getTabuleiro()->imprimeTabuleiro();


    return 0;
}
