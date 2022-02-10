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
    void setNo(int id, int idPai);
    No* buscaNo(int id); 
    No* getRaiz();
    void fazerJogadas();

private:
    int ordem;
    list<No *> nos;
    list<No *> nosAbertos;
    list<No *> nosFechados;
    No *raiz;
};

#endif