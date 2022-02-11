#ifndef GRAFO
#define GRAFO

#include <iostream>
#include <list>
#include <vector>
#include "No.h"

class Grafo
{
public:
    Grafo();
    ~Grafo();
    vector<No *> getNos();
    list<No *> getNosAbertos();
    list<No *> getNosFechados();
    void ramificaNo(int idNo);
    void setNo(int idPai, int coluna, int linha);
    No* buscaNo(int id); 
    No* getRaiz();
    void fazerJogadas();
    void criaArvore();
    vector<No *> caminho(int id);

private:
    int ordem;
    vector<No *> nos;
    list<No *> nosAbertos;
    list<No *> nosFechados;
    No *raiz;
};

#endif