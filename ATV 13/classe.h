#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

class Arma
{
protected:
    string nome;
    int id;
    int danoMin;
    int danoMax;
public:
    Arma(int vetor[4]);
    void imprimeDados();
    int obtemID();
    void imprimeArma(int vetor[4]);
    int calculaDano();
    string obtemNome(int id);
    ~Arma();
};

class Personagem
{
protected:
    int vida;
    int mana;
    int forca;
    int magia;
    int resFisico;
    int resMagia;
    int agilidade;
    Arma *arma;
    int idArma[7];
    int idMagia[7];
public:
    Personagem(int vetor[11]);
    void imprimeDados();
    int mostraVida();
    int mostraMana();
    int trocarArma();
    void recebeDano(int dano, int flag);
    int esquiva();
    int ataqueFisico();
    int ataqueMagia();
    ~Personagem();
};

class Magia
{
private:
    string nome;
    int id;
    int dano;
    int gasto;
public:
    Magia(int vetor[4]);
    void imprimeDados();
    ~Magia();
};
