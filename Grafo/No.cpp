#include <iostream>
using namespace std;
#include "../Tabuleiro.cpp"
#include "No.h"
#include "string"

No::No(int idp, int idPaip, int coluna, int linha, int jogadorp, Tabuleiro *tab)
{
    tabuleiro = new Tabuleiro();
    preencheTabuleiro(tab);
    id = idp;
    idPai = idPaip;

    jogador = jogadorp;
    heuristica = 0;
    estado = tabuleiro->fazerJogada(jogadorp, coluna, linha);
    calculaHeuristica();
};

void No::preencheTabuleiro(Tabuleiro *tab)
{

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {

            tabuleiro->fazerJogada(tab->verificarCasa(i, j), i, j);
        }
    }
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

void No::addFilho(No *no)
{
    filhos.push_back(no);
};

vector<No *> No::getFilhos()
{
    return filhos;
};

int No::getIdPai(){
    return idPai;
}

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
                        if (tabuleiroTiraTeima[k][k] == 0)
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
                    }
                    heuristica += contador;
                    contador = 0;
                }

                if ((i == 0 && j == 3) || (i == 1 && j == 2) || (i == 2 && j == 1) || (i == 3 && j == 0))
                {

                    if (tabuleiroTiraTeima[0][3] == 0)
                    {
                        if (tabuleiro->verificarCasa(0, 3) == 2)
                        {
                            tabuleiroTiraTeima[0][3] = 1;
                            contador = 0;
                            break;
                        }

                        if (tabuleiro->verificarCasa(0, 3) == 1)
                        {
                            tabuleiroTiraTeima[0][3] = 1;
                            contador += 3;
                        }

                        if (tabuleiro->verificarCasa(0, 3) == 0)
                        {
                            tabuleiroTiraTeima[0][3] = 1;
                            contador += 1;
                        }
                    }

                    if (tabuleiroTiraTeima[1][2] == 0)
                    {
                        if (tabuleiro->verificarCasa(1, 2) == 2)
                        {
                            tabuleiroTiraTeima[1][2] = 1;
                            contador = 0;
                            break;
                        }

                        if (tabuleiro->verificarCasa(1, 2) == 1)
                        {
                            tabuleiroTiraTeima[1][2] = 1;
                            contador += 3;
                        }

                        if (tabuleiro->verificarCasa(1, 2) == 0)
                        {
                            tabuleiroTiraTeima[1][2] = 1;
                            contador += 1;
                        }
                    }

                    if (tabuleiroTiraTeima[2][1] == 0)
                    {
                        if (tabuleiro->verificarCasa(2, 1) == 2)
                        {
                            tabuleiroTiraTeima[2][1] = 1;
                            contador = 0;
                            break;
                        }

                        if (tabuleiro->verificarCasa(2, 1) == 1)
                        {
                            tabuleiroTiraTeima[2][1] = 1;
                            contador += 3;
                        }

                        if (tabuleiro->verificarCasa(2, 1) == 0)
                        {
                            tabuleiroTiraTeima[2][1] = 1;
                            contador += 1;
                        }
                    }

                    if (tabuleiroTiraTeima[3][0] == 0)
                    {
                        if (tabuleiro->verificarCasa(3, 0) == 2)
                        {
                            tabuleiroTiraTeima[3][0] = 1;
                            contador = 0;
                            break;
                        }

                        if (tabuleiro->verificarCasa(3, 0) == 1)
                        {
                            tabuleiroTiraTeima[3][0] = 1;
                            contador += 3;
                        }

                        if (tabuleiro->verificarCasa(3, 0) == 0)
                        {
                            tabuleiroTiraTeima[3][0] = 1;
                            contador += 1;
                        }
                    }
                }

                for (size_t w = 0; w < 4; w++)
                {
                    if (tabuleiroTiraTeima[i][w] == 0)
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
                }

                heuristica += contador;

                contador = 0;

                for (size_t w = 0; w < 4; w++)
                {
                    if (tabuleiroTiraTeima[w][j] == 0)
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
                }

                heuristica += contador;

                contador = 0;
            }
        }
    }
};