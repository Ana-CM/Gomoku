#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "../Grafo/Grafo.h"
#include "../Grafo/No.h"
#include "../Tabuleiro.cpp"
#include <list>
#include <vector>

using namespace std;

int buscarSolucao(No *atual,vector<No*> *abertos,vector<No*> *fechados,Grafo *gomoku);

int main(){ 

// Considerando peso da aresta = heuristica da jogada
// vou andar e procurar o com maior heuristica
// somar e procurar o maior sempre
// e mantendo os possiveis caminhos em uma lista de abertos
// cada vez q escolho 1 caminho ele se torna um fechado
// final eu exibo a melhor solucao achada com maior custo real
    Grafo *gomoku = new Grafo();
    list<No*>::iterator it1;
    vector<No *> *abertos;
    for (it1 = gomoku->getNos().begin(); it1 != gomoku->getNos().end();it1++)
    {
        abertos->push_back(*it1);
    }
    vector<No*> *fechados;
    No *raiz = gomoku->getRaiz();
    gomoku->ramificaNo(raiz->getId());
    int result = buscarSolucao(raiz,abertos,fechados,gomoku);
    cout << result;
    return 0;
}


int buscarSolucao(No *atual,vector<No*> *abertos,vector<No*> *fechados,Grafo *gomoku) {

    int heuristica=0;
    int idHeuristica = 0;
    No *candidato;
    for(int i=0;i<atual->getFilhos().size();i++)
    {

        int heuristicaAtual = atual->getFilhos().at(i)->getHeuristica();
        if(heuristicaAtual>heuristica)
        {
            heuristica = heuristicaAtual;
            idHeuristica = atual->getFilhos().at(i)->getId();
            candidato = gomoku->buscaNo(idHeuristica);
            cout << idHeuristica << endl;
        }
    }
    vector<No*>::iterator it1 = (abertos->begin() + (candidato->getId() - 1));
    abertos->erase(it1);
    fechados->push_back(candidato);
    if(candidato->getFilhos().size()>0) {
        contador += heuristica;
        return buscarSolucao(candidato,abertos,fechados,gomoku) + contador;
    }
    else
        return contador;
}
    // gomoku->ramificaNo(raiz->getId());
    // gomoku->ramificaNo(raiz->getFilhos().at(0)->getId());
    // cout << "Filhos: " << raiz->getFilhos().size() << endl;

    // for (size_t i = 0; i < raiz->getFilhos().at(0)->getFilhos().size(); i++)
    // {
    //     raiz->getFilhos().at(0)->getFilhos().at(i)->getTabuleiro()->imprimeTabuleiro();
    //     cout << "Estado" << raiz->getFilhos().at(0)->getFilhos().at(i)->getEstado() << endl;
    //     cout << "Heuristica" << raiz->getFilhos().at(0)->getFilhos().at(i)->getHeuristica() << endl;
    // }

    // return 0;