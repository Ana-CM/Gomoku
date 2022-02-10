#ifndef NO
#define NO

#include "../Tabuleiro.cpp"
#include <iostream>
#include <list>
#include <string>
using namespace std;

class No
{
public:
    No(int id, int idPai, int jogador, Tabuleiro *tabuleiro);
    ~No();
    int getId();
    Tabuleiro *getTabuleiro();
    int getHeuristica();
    int getEstado();
    void addFilho(int id);
    int getJogador();
    void calculaHeuristica();

private:
    int id;
    int idPai;
    Tabuleiro *tabuleiro;
    int heuristica;
    int jogador;
    int estado;
    list<int> idsFilhos;
};

#endif