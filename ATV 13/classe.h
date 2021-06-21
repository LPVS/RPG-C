#include <iostream>
#include <string.h>

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
    Personagem(int vida, int mana, int forca, int magia, int resFisico, int resMagia, int agilidade);
    void imprimeDados();
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
    bool dano;
    int gasto;
public:
    Magia(string nome, int id, bool dano, int gasto);
    ~Magia();
};
