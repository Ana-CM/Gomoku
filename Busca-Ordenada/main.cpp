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

void buscarSolucao(No *atual,vector<No*> abertos,vector<No*> fechados,Grafo *gomoku,int *contador);

int main(){ 

// Considerando peso da aresta = heuristica da jogada
// vou andar e procurar o com maior heuristica
// somar e procurar o maior sempre
// e mantendo os possiveis caminhos em uma lista de abertos
// cada vez q escolho 1 caminho ele se torna um fechado
// final eu exibo a melhor solucao achada com maior custo real
    Grafo *gomoku = new Grafo();
    vector<No*> fechados;
    No *raiz = gomoku->getRaiz();
    gomoku->ramificaNo(raiz->getId());
    vector<No*> abertos = raiz->getFilhos();
    int *contador = 0;
    buscarSolucao(raiz,abertos,fechados,gomoku,contador);
    return 0;
}


void buscarSolucao(No *atual,vector<No*> abertos,vector<No*> fechados,Grafo *gomoku,int *contador) {

    int heuristica=0;
    int idHeuristica = 0;
    No *candidato;
    for(int i=0;i<atual->getFilhos().size();i++)
    {

        int heuristicaAtual = atual->getFilhos().at(i)->getHeuristica();
        cout << heuristicaAtual << endl;
        if(heuristicaAtual>heuristica)
        {
            cout << "entrou aqui" << endl;
            heuristica = heuristicaAtual;
            idHeuristica = atual->getFilhos().at(i)->getId();
            candidato = gomoku->buscaNo(idHeuristica);
        }
    }
    vector<No*>::iterator it1 = (abertos.begin() + (candidato->getId() - 1));
    abertos.erase(it1);
    fechados.push_back(candidato);
    if(candidato->getFilhos().size()>0) {
        cout << "TA ENTRANDO AQUI?" << endl;
        contador += heuristica;
        cout << contador << endl;
        buscarSolucao(candidato,abertos,fechados,gomoku,contador);
    }
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