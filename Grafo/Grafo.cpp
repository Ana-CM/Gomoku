
#include <iostream>
#include "Grafo.h"
#include "../Tabuleiro.cpp"
#include "No.h"
#include "list"

using namespace std;

Grafo::Grafo()
{
    raiz = new No(1, -1, 0, new Tabuleiro());
    ordem = 1;
    nos.push_back(raiz);
    cout << "SAI DO GRAFO" << endl;
};


void Grafo::setNo(int id, int idPai)
{

    No *noPai = buscaNo(idPai);

    if (noPai == raiz || noPai->getJogador() == 2)
    {
        noPai->addFilho(id);
        No *novoNo = new No(id, idPai, 1, noPai->getTabuleiro());
        nos.push_back(novoNo);
    }
    else
    {
        noPai->addFilho(id);
        No *novoNo = new No(id, idPai, 2, noPai->getTabuleiro());
        nos.push_back(novoNo);
    }
};

list<No *> Grafo::getNos()
{
    return nos;
};

No *Grafo::getRaiz()
{
    return raiz;
}
No *Grafo::buscaNo(int id)
{
    std::list<No *>::iterator it = nos.begin();
    for (; it != nos.end(); ++it)
    {
        if ((*it)->getId() == id)
        {
            return *it;
        }
    }
    return nullptr;
};
