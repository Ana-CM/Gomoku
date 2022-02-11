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

    No *raiz = gomoku->getRaiz();
    gomoku->ramificaNo(raiz->getId());
    gomoku->ramificaNo(raiz->getFilhos().at(0)->getId());
    gomoku->ramificaNo(raiz->getFilhos().at(0)->getFilhos().at(0));

    
    cout << "Filhos: " << raiz->getFilhos().size() << endl;

    for (size_t i = 0; i < raiz->getFilhos().at(0)->getFilhos().size(); i++)
    {
        raiz->getFilhos().at(0)->getFilhos().at(i)->getTabuleiro()->imprimeTabuleiro();
        cout << "Estado" << raiz->getFilhos().at(0)->getFilhos().at(i)->getEstado() << endl;
        cout << "Heuristica" << raiz->getFilhos().at(0)->getFilhos().at(i)->getHeuristica() << endl;
    }

    return 0;
}
