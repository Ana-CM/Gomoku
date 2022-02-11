
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

// void Grafo::criaArvore()
// {
//     int contId = 1;
//     No *no = buscaNo(contId);

//     for (size_t k = 0; k < 16; k++)
//     {
//         setNo(no->getId());
//     }

//     contId++;
//     // for (size_t w = 15; w >= 0; w--)
//     // {
//     for (size_t i = w + 1; i >= 0; i--)
//     {
//         if (i > 0)
//         {
//             for (size_t j = 0; j < 14; j++)
//             {
//                 setNo(no->getId());
//             }
//             contId++;
//         }
//     }
// }
// // }

// list<No *> Grafo::caminho(int id)
// {
//     list<No *> result;
//     No *no = buscaNo(id);

//     if (id == 1)
//     {
//         caminhoAux(no, result);
//     }

//     return result;
// }
// list<No *> Grafo::caminhoAux(No *no, list<No*> result)
// {
//     if (no->getIdPai() != 0)
//     {
//         return caminhoAux(buscaNo(no->getIdPai()), result.push_back(buscaNo(no->getIdPai())));
//     }
// }

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
