#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include "../Grafo/Grafo.h"
#include "../Grafo/No.h"
#include "../Tabuleiro.cpp"
#include <bits/stdc++.h>

vector<No *> buscaGulosa(Grafo *gomoku);

int main()
{
    Grafo *gomoku = new Grafo();
    No *no = gomoku->getRaiz();
    No *aux;
    int cont = 0;
    while (cont != 15)
    {
        gomoku->ramificaNo(no->getId());
        aux = no;
        no = aux->getFilhos().at(0);
        cont++;
    }
    cout << gomoku->getNos().size()
         << endl;
    cout << "=============================================" << endl;
    vector<No *> caminho = buscaGulosa(gomoku);

    if (!caminho.empty())
    {
        int custoReal = 0;
        for (size_t i = 0; i < caminho.size(); i++)
        {
            cout << "Tabuleiro : " << caminho.at(i)->getId() << endl;
            caminho.at(i)->getTabuleiro()->imprimeTabuleiro();
            cout << endl;
            custoReal += caminho.at(i)->getHeuristica();
        }

        cout << "Custo Real: " << custoReal << endl;
    }
    else
    {
        cout << "Não Foi Encontrada Solução." << endl;
    }
}

vector<No *> buscaGulosa(Grafo *gomoku)
{
    vector<No *> abertos;
    vector<No *> caminho;
    No *noAtual = gomoku->getRaiz();
    int custoReal = 0;
    bool flag = true;
    while (flag)
    {

        if (noAtual->getEstado() == 1)
        {
            cout << "Heuristica : " << noAtual->getHeuristica() << endl;
            noAtual->getTabuleiro()->imprimeTabuleiro();
            caminho = gomoku->caminho(noAtual->getId());
            flag = false;
        }

        else if (noAtual->getEstado() == 2 || noAtual->getEstado() == 3)
        {

            if (!noAtual->getFilhos().empty())
            {
                cout << "Heuristica : " << noAtual->getHeuristica() << endl;
                noAtual->getTabuleiro()->imprimeTabuleiro();
                vector<No *> filhosOrdenados = noAtual->getFilhos();

                abertos.insert(abertos.end(), filhosOrdenados.begin(), filhosOrdenados.end());
                cout << "Filhos : " << noAtual->getFilhos().size() << endl;

                //Ordenação
                sort(abertos.begin(), abertos.end());

                cout << "Abertos " << abertos.size() << endl;
                cout << endl;
            }

            noAtual = abertos.front();
            abertos.clear();
        }
    }
    if (flag == false)
    {
        cout << "Encontrado Solução" << endl;
    }

    return caminho;
}
