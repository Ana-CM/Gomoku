#ifndef TABULEIRO
#define TABULEIRO

#include <iostream>
#include <vector>

using namespace std;

class Tabuleiro
{

public:
    Tabuleiro()
    {
        tabuleiro.clear();

        tabuleiro.resize(4);

        for (int i = 0; i < 4; i++)
        {
            tabuleiro[i].resize(4);
            for (size_t j = 0; j < 4; j++)
            {
                tabuleiro[i][j] = 0;
            }
            
        }

        imprimeTabuleiro();
    }

    void imprimeTabuleiro()
    {

        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                cout << tabuleiro[i][j] << "-";
            }
            cout << endl;
        }
    }

    void fazerJogada(int coluna, int linha, int jogador)
    {
        tabuleiro[coluna][linha] = jogador;
    }

    int verificarCasa(int coluna, int linha)
    {
        return tabuleiro[coluna][linha];
    }

private:
    vector<vector<int>> tabuleiro;
};

#endif