#ifndef NO
#define NO

#include "../Tabuleiro.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class No
{
public:
    No(int id, int idPai, int coluna, int linha, int jogador, Tabuleiro *tabuleiro);
    ~No();
    int getId();
    Tabuleiro *getTabuleiro();
    int getHeuristica();
    int getEstado();
    int getIdPai();
    void addFilho(No* no);
    int getJogador();
    void calculaHeuristica();
    vector<No*> getFilhos();
    void preencheTabuleiro(Tabuleiro *tab);

private:
    int id;
    int idPai;
    Tabuleiro *tabuleiro;
    int heuristica;
    int jogador;
    int estado;
    vector<No*> filhos;
};

#endif