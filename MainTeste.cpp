#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "./Grafo/Grafo.h"
#include "./Grafo/No.h"
#include "Tabuleiro.cpp"

using namespace std;

int main()
{
    Grafo *gomoku = new Grafo();

    gomoku->setNo(2, 1);
    gomoku->setNo(3, 2);
    gomoku->setNo(4, 3);
    gomoku->setNo(5, 4);
    gomoku->setNo(6, 5);
    gomoku->setNo(7, 6);
    gomoku->setNo(8, 7);
    gomoku->buscaNo(8)->getTabuleiro()->imprimeTabuleiro();
    cout <<"Estado" <<  gomoku->buscaNo(8)->getEstado();
    cout <<"Heuristica" << gomoku->buscaNo(8)->getHeuristica();

    return 0;
}
