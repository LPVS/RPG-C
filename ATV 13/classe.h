#include <iostream>
#include <string.h>

using namespace std;

class Personagem
{
private:
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
