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
    int id;
    int danoMin;
    int danoMax;
public:
    Arma(int id, int danoMin, int danoMax);
    ~Arma();
};

class Magia
{
private:
    int id;
    bool dano;
    int gasto;
public:
    Magia(int id, bool dano, int gasto);
    ~Magia();
};
