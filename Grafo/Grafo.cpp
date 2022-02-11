
#include <iostream>
#include "Grafo.h"
#include "../Tabuleiro.cpp"
#include "No.h"
#include <list>

using namespace std;

Grafo::Grafo()
{
    raiz = new No(1, -1, 0, 0, 0, new Tabuleiro());
    ordem = 1;
    nos.push_back(raiz);
};

vector<No *> Grafo::caminho(int id)
{
    vector<No *> result;

    No *no = buscaNo(id);
    No *aux;
    result.push_back(no);

    while (no->getIdPai() != -1)
    {   
        aux = no;
        no = buscaNo(aux->getIdPai());
        result.push_back(no);
    }

    return result;
}

void Grafo::ramificaNo(int idNo)
{
    No *no = buscaNo(idNo);
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {

            if (no->getTabuleiro()->verificarCasa(j, i) == 0)
            {
                setNo(idNo, j, i);
            }
        }
    }
}
void Grafo::setNo(int idPai, int coluna, int linha)
{

    No *noPai = buscaNo(idPai);

    if (noPai == raiz || noPai->getJogador() == 2)
    {

        ordem++;
        No *novoNo = new No(ordem, idPai, coluna, linha, 1, noPai->getTabuleiro());
        nos.push_back(novoNo);
        noPai->addFilho(buscaNo(ordem));
    }
    else
    {

        ordem++;
        No *novoNo = new No(ordem, idPai, coluna, linha, 2, noPai->getTabuleiro());
        nos.push_back(novoNo);
        noPai->addFilho(buscaNo(ordem));
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
