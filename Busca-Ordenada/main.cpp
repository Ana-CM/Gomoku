#include <iostream>
#include <vector>
#include <queue>
#include "../Tabuleiro.cpp"
#include "../Grafo/No.h"
#include "../Grafo/Grafo.h"

using namespace std;

vector<No *> ordenacao(vector<No *> vec, Grafo *grafo);

int main()
{
    vector<int> abertos;
    vector<int> fechados;
    vector<No *> ordenada;
    Grafo *gomoku = new Grafo();
    No *aux;
    No *no;
    int cont = 0;


    no = gomoku->getRaiz();
    while (cont != 15)
    {
        gomoku->ramificaNo(no->getId());
        aux = no;
        no = aux->getFilhos().at(0);
        cont++;
    }

    vector<No *> caminho;
    no = gomoku->getRaiz();
    abertos.push_back(no->getId());

    while (true)
    {
        //gomoku->ramificaNo(no->getId());

        // cout << endl;
        // cout << "Abertos: ";
        // for (auto i = abertos.begin(); i != abertos.end(); ++i) {
        //      cout << *i << " " ;
        // }
        // cout << endl;

        // cout << "Fechados: ";
        // for (auto i = fechados.begin(); i != fechados.end(); ++i) {
        //      cout << *i << " " ;
        // }
        // cout << endl;
        // cout << endl;

        fechados.push_back(no->getId());

        for (auto i = abertos.begin(); i != abertos.end(); ++i)
        {
            if (*i == no->getId())
            {
                abertos.erase(i);
                break;
            }
        }

        if (no->getEstado() == 1)
        {
            cout << "Achou!" << endl;
            cout << endl;
            break;
        }

        if (no->getEstado() == 2)
        {
            cout << "perdeu" << endl;
            break;

            ordenada = ordenacao(ordenada, gomoku);
            no = ordenada.front();
            ordenada.erase(ordenada.begin());

            cout << "Heuristica : " << no->getHeuristica() << endl;
            no->getTabuleiro()->imprimeTabuleiro();

            cout << endl;
        }

        if (no->getEstado() == 3)
        {

            for (size_t i = 0; i < no->getFilhos().size(); i++)
            {
                ordenada.push_back(no->getFilhos().at(i));
                abertos.push_back((no->getFilhos().at(i))->getId());
            }

            ordenada = ordenacao(ordenada, gomoku);
            no = ordenada.front();
            ordenada.erase(ordenada.begin());

            cout << "Heuristica : " << no->getHeuristica() << endl;
            no->getTabuleiro()->imprimeTabuleiro();

            cout << endl;
        }
    }

    no->getTabuleiro()->imprimeTabuleiro();
    cout << "Heuristica : " << no->getHeuristica() << endl;
    no->getTabuleiro()->imprimeTabuleiro();
    cout << endl;

    caminho = gomoku->caminho(no->getId());
    int totalCaminho = 0;
    for (int i = caminho.size() - 1; i >= 0; i--)
    {
        totalCaminho += caminho.at(i)->getHeuristica();
        cout << caminho.at(i)->getId() << " - ";
    }
    cout << endl;
    cout << "Custo Real: " << totalCaminho << endl;
    return 0;
}

vector<No *> ordenacao(vector<No *> vec, Grafo *grafo)
{

    int nosDoCaminho;
    int nosDoCaminho2;
    vector<No *> caminho;
    vector<No *> caminho2;
    int i, j;
    for (i = 0; i < vec.size() - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < vec.size() - i - 1; j++)
        {

            caminho = grafo->caminho(vec[j]->getId());
            caminho2 = grafo->caminho(vec[j + 1]->getId());
            for (int w = 0; w < caminho.size(); w++)
            {
                nosDoCaminho += caminho.at(w)->getHeuristica();
            }
            for (int k = 0; k < caminho.size(); k++)
            {
                nosDoCaminho2 += caminho2.at(k)->getHeuristica();
            }
            if (nosDoCaminho >= nosDoCaminho2)
            {
                No *aux = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = aux;
            }
        }
    }

    return vec;
};