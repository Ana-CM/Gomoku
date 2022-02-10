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

    // gomoku->setNo(2, 1);
    // gomoku->setNo(3, 2);
    // gomoku->setNo(4, 3);
    // gomoku->setNo(5, 4);
    // gomoku->setNo(6, 5);
    // gomoku->setNo(7, 6);
    // gomoku->setNo(8, 7);
    // gomoku->buscaNo(8)->getTabuleiro()->imprimeTabuleiro();
    No *raiz = gomoku->getRaiz();
    gomoku->ramificaNo(raiz->getId());
    gomoku->ramificaNo(raiz->getFilhos().at(0)->getId());
    cout << "Filhos: " << raiz->getFilhos().size() << endl;

    for (size_t i = 0; i < raiz->getFilhos().at(0)->getFilhos().size(); i++)
    {
        raiz->getFilhos().at(0)->getFilhos().at(i)->getTabuleiro()->imprimeTabuleiro();
        cout << "Estado" << raiz->getFilhos().at(0)->getFilhos().at(i)->getEstado() << endl;
        cout << "Heuristica" << raiz->getFilhos().at(0)->getFilhos().at(i)->getHeuristica() << endl;
    }

    return 0;
}
