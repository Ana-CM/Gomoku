#include <iostream>
using namespace std;
#include "../Tabuleiro.cpp"
#include "No.h"
#include "string"

No::No(int idp, int idPaip, int colunap, int linhap, int jogadorp, Tabuleiro *tab)
{
    id = idp;
    idPai = idPaip;
    tabuleiro = tab;
    
    tabuleiro->fazerJogada(colunap, linhap, jogadorp);
    
    //heuristica = calculaheuristica();
};

int No::getId()
{
    return id;
};

Tabuleiro* No::getTabuleiro()
{
    return tabuleiro;
};

int No::getHeuristica()
{
    return heuristica;
};

string No::getEstado()
{
    return estado;
};

void No::addFilho(int id)
{
    idsFilhos.push_back(id);
};

//int No:: calculaHeuristica();