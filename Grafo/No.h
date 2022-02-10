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
    No(int id, int idPai, int coluna, int linha, int jogador, Tabuleiro *tabuleiro);
    ~No();
    int getId();
    Tabuleiro* getTabuleiro();
    int getHeuristica();
    string getEstado();
    void addFilho(int id);

private:
    int id;
    int idPai;
    Tabuleiro* tabuleiro;
    int heuristica;
    string estado;
    list<int> idsFilhos;
    int calculaHeuristica();
};

#endif