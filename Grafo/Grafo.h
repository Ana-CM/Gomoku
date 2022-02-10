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
    void setNo(int id, int idPai, int coluna, int linha, int jogador);
    No* buscaNo(int id); 
    No* getRaiz();

private:
    int ordem;
    list<No *> nos;
    No *raiz;
};

#endif