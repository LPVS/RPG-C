#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
using namespace std;

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
    string idArma;
    string idMagia;
public:
    Personagem(int vetor[7]);
    void imprimeDados();
    int mostraVida();
    int calculaDano();
    int ataqueFisico();
    int ataqueMagia();
    ~Personagem();
};

class Arma
{
protected:
    string nome;
    int id;
    int danoMin;
    int danoMax;
public:
    Arma(string nome, int id, int danoMin, int danoMax);
    ~Arma();
};

class Magia
{
private:
    string nome;
    int id;
    int dano;
    int gasto;
public:
    Magia(string nome, int id, int dano, int gasto);
    ~Magia();
};
