
#include <iostream>
#include "Grafo.h"
#include "../Tabuleiro.cpp"
#include "No.h"
#include "list"

using namespace std;

Grafo::Grafo()
{
    raiz = new No(1, -1, 0, 0, 0, new Tabuleiro());
    ordem = 1;
    nos.push_back(raiz);
    cout << "SAI DO GRAFO" << endl;

};

void Grafo::setNo(int id, int idPai, int coluna, int linha, int jogador)
{
    No *noPai = buscaNo(idPai);
    noPai->addFilho(id);
    Tabuleiro *tabuleiro = nullptr;
    No *novoNo = new No(id, idPai, coluna, linha, jogador, tabuleiro);

    nos.push_back(novoNo);
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
