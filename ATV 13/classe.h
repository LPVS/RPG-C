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
    int calculaDano();
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
    string idArma;
    string idMagia;
public:
    Personagem(int vetor[7]);
    void imprimeDados();
    int mostraVida();
    int mostraMana();
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
