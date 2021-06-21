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
    int idArma[7];
    int idMagia[7];
public:
    Personagem(int hp, int mp, int str, int mag, int armor, int magArmor, int agi, int idWeapon, int idMagic);
    ~Personagem();
};
