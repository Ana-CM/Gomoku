#include <iostream>
#include <vector>
#include <queue>
#include "../Tabuleiro.cpp"
#include "../Grafo/No.h"
#include "../Grafo/Grafo.h"

using namespace std;

int main()
{
    vector<int> abertos;
    vector<int> fechados;
    queue<No*> fila;
    Grafo *gomoku = new Grafo();
    No *no = gomoku->getRaiz();
    vector<No *> caminho;

    abertos.push_back(no->getId());

    while( true ) {

        gomoku->ramificaNo(no->getId());  

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

        for (auto i = abertos.begin(); i != abertos.end(); ++i) {
            if (*i == no->getId()) {
                abertos.erase(i);
                break;
            }
        }

        if ( no->getEstado() == 1) {
            cout << "Achou!" << endl;
            cout << endl;
            break;
        }
        
        if ( no->getEstado() == 2) {
            cout << "perdeu" << endl;
            break;
            no = fila.front();
            fila.pop(); 
        }

        if ( no->getEstado() == 3) {

            for (size_t i = 0; i < no->getFilhos().size(); i++)
            {
                fila.push( no->getFilhos().at(i) );
                abertos.push_back((no->getFilhos().at(i))->getId());
            } 

            no = fila.front();
            fila.pop(); 
        }
    }

    no->getTabuleiro()->imprimeTabuleiro();
    
    cout << endl;

   caminho = gomoku->caminho(no->getId());

    for (size_t i = fechados.size() - 1; i >= 0 ; i--)
    {
        cout << caminho.at(i)->getId() << endl;
    }

    return 0;
}