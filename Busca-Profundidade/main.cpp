#include <iostream>
#include <vector>
#include <stack>
#include "../Tabuleiro.cpp"
#include "../Grafo/No.h"
#include "../Grafo/Grafo.h"

using namespace std;

int main()
{
    vector<int> abertos;
    vector<int> fechados;
    stack<No*> pilha;
    Grafo *gomoku = new Grafo();
    No *no = gomoku->getRaiz();

    abertos.push_back(no->getId());

    while( true ) {

        gomoku->ramificaNo(no->getId());  

        cout << endl;
        cout << "Abertos: ";
        for (auto i = abertos.begin(); i != abertos.end(); ++i) {
             cout << *i << " " ;
        }
        cout << endl;

        cout << "Fechados: ";
        for (auto i = fechados.begin(); i != fechados.end(); ++i) {
             cout << *i << " " ;
        }
        cout << endl;
        cout << endl;

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
            no = pilha.top();
            pilha.pop(); 
        }

        if ( no->getEstado() == 3) {

            for (size_t i = 0; i < no->getFilhos().size(); i++)
            {
                pilha.push( no->getFilhos().at(i) );
                abertos.push_back((no->getFilhos().at(i))->getId());
            } 

            no = pilha.top();
            pilha.pop(); 
        }
    }

    no->getTabuleiro()->imprimeTabuleiro();
    //TODO: imprimir caminho.

    return 0;
}
    

