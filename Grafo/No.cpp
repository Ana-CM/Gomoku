#include <iostream>
using namespace std;
#include "../Tabuleiro.cpp"
#include "No.h"
#include "string"

No::No(int idp, int idPaip, int jogadorp, Tabuleiro *tab)
{
    id = idp;
    idPai = idPaip;
    tabuleiro = tab;
    jogador = jogadorp;
    heuristica = 0;
    estado = tabuleiro->fazerJogada(jogadorp);
    calculaHeuristica();
};

int No::getId()
{
    return id;
};

Tabuleiro *No::getTabuleiro()
{
    return tabuleiro;
};

int No::getHeuristica()
{
    return heuristica;
};

int No::getEstado()
{
    return estado;
};

int No::getJogador()
{
    return jogador;
};

void No::addFilho(int id)
{
    idsFilhos.push_back(id);
};

void No::calculaHeuristica()
{

    int contador = 0;
    bool pcaBranca = true;

    vector<vector<int>> tabuleiroTiraTeima;
    tabuleiroTiraTeima.clear();

    tabuleiroTiraTeima.resize(4);

    for (int i = 0; i < 4; i++)
    {
        tabuleiroTiraTeima[i].resize(4);
        for (size_t j = 0; j < 4; j++)
        {
            tabuleiroTiraTeima[i][j] = 0;
        }
    }

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if (tabuleiro->verificarCasa(i, j) == 1 && tabuleiroTiraTeima[i][j] == 0)
            {

                if (i == j)
                {

                    for (int k = 0; k < 4; k++)
                    {
                        if (tabuleiro->verificarCasa(k, k) == 2)
                        {
                            tabuleiroTiraTeima[k][k] = 1;
                            contador = 0;
                            break;
                        }

                        if (tabuleiro->verificarCasa(k, k) == 1)
                        {
                            tabuleiroTiraTeima[k][k] = 1;
                            contador += 3;
                        }

                        if (tabuleiro->verificarCasa(k, k) == 0)
                        {
                            tabuleiroTiraTeima[k][k] = 1;
                            contador += 1;
                        }
                    }
                    heuristica += contador;
                    contador = 0;
                }

                if ((i == 0 && j == 3) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 3 && j == 0))
                {

                    for (int w = 0; w < 4; w++)
                    {
                        for (int k = 3; k >= 0; k--)
                        {
                            if (tabuleiro->verificarCasa(w, k) == 2)
                            {
                                tabuleiroTiraTeima[w][k] = 1;
                                contador = 0;
                                break;
                            }

                            if (tabuleiro->verificarCasa(w, k) == 1)
                            {
                                tabuleiroTiraTeima[w][k] = 1;
                                contador += 3;
                            }

                            if (tabuleiro->verificarCasa(w, k) == 0)
                            {
                                tabuleiroTiraTeima[w][k] = 1;
                                contador += 1;
                            }
                        }
                    }
                    heuristica += contador;
                    contador = 0;
                }

                for (size_t w = 0; w < 4; w++)
                {
                    if (tabuleiro->verificarCasa(i, w) == 2)
                    {
                        tabuleiroTiraTeima[i][w] = 1;
                        contador = 0;
                        break;
                    }

                    if (tabuleiro->verificarCasa(i, w) == 1)
                    {
                        tabuleiroTiraTeima[i][w] = 1;
                        contador += 3;
                    }

                    if (tabuleiro->verificarCasa(i, w) == 0)
                    {
                        tabuleiroTiraTeima[i][w] = 1;
                        contador += 1;
                    }
                }

                heuristica += contador;
                contador = 0;

                for (size_t w = 0; w < 4; w++)
                {
                    if (tabuleiro->verificarCasa(w, j) == 2)
                    {
                        tabuleiroTiraTeima[w][j] = 1;
                        contador = 0;
                        break;
                    }

                    if (tabuleiro->verificarCasa(w, j) == 1)
                    {
                        tabuleiroTiraTeima[w][j] = 1;
                        contador += 3;
                    }

                    if (tabuleiro->verificarCasa(w, j) == 0)
                    {
                        tabuleiroTiraTeima[w][j] = 1;
                        contador += 1;
                    }
                }

                heuristica += contador;
                contador = 0;
            }
        }
    }
};