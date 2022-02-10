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
                cout << tabuleiro[i][j] << "|";
            }
            cout << endl;
        }
    }

    int fazerJogada(int jogador)
    {

        for (size_t i = 0; i < 4; i++)
        {
            for (size_t j = 0; j < 4; j++)
            {
                if (tabuleiro[i][j] == 0)
                {
                    tabuleiro[i][j] = jogador;
                    return ganhouPreta();
                }
            }
        }

        return 4;

    }

    int verificarCasa(int coluna, int linha)
    {
        return tabuleiro[linha][coluna];
    }

private:
    vector<vector<int>> tabuleiro;
    int vencedor;

    int ganhouPreta()
    {

        for (int i = 0; i < 4; i++)
        { // verificando se houve vitoria por linha ou coluna

            if ((0 != tabuleiro[0][i]) && (tabuleiro[0][i] == tabuleiro[1][i]) && (tabuleiro[1][i] == tabuleiro[2][i]) && (tabuleiro[2][i] == tabuleiro[3][i]))
            {
                if (1 == tabuleiro[0][i])
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }

            if ((0 != tabuleiro[i][0]) && (tabuleiro[i][0] == tabuleiro[i][1]) && (tabuleiro[i][1] == tabuleiro[i][2]) && (tabuleiro[i][2] == tabuleiro[i][3]))
            {
                if (1 == tabuleiro[i][0])
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
        }

        // verificando se houve vitoria por diagonal
        if ((0 != tabuleiro[0][0]) && (tabuleiro[0][0] == tabuleiro[1][1]) && (tabuleiro[1][1] == tabuleiro[2][2]) && (tabuleiro[2][2] == tabuleiro[3][3]))
        {
            if (1 == tabuleiro[0][0])
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else if ((0 != tabuleiro[0][3]) && (tabuleiro[0][3] == tabuleiro[1][2]) && (tabuleiro[1][2] == tabuleiro[2][1]) && (tabuleiro[2][1] == tabuleiro[3][0]))
        {
            if (1 == tabuleiro[0][3])
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }

        bool vazio = false;

        // verificando se houve empate
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (0 == tabuleiro[i][j])
                {
                    vazio = true;
                    break;
                }
            }
        }

        if (!vazio)
        {
            return 2;
        }

        return 3;
    }
};

#endif