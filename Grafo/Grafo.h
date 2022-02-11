#ifndef GRAFO
#define GRAFO

#include <iostream>
#include <list>
#include "No.h"

class Grafo
{
public:
    Grafo();
    ~Grafo();
    list<No *> getNos();
    list<No *> getNosAbertos();
    list<No *> getNosFechados();
    void ramificaNo(int idNo);
    void setNo(int idPai, int coluna, int linha);
    No* buscaNo(int id); 
    No* getRaiz();
    void fazerJogadas();
    void criaArvore();
    // list<No *> caminho(int id);
    // void caminho(int id);
private:
    int ordem;
    list<No *> nos;
    list<No *> nosAbertos;
    list<No *> nosFechados;
    No *raiz;
};

#endif