#include "classe.h"
#include <iostream>
using namespace std;

Personagem::Personagem (int vida, int mana, int forca, int magia, int resFisico, int resMagia, int agilidade) {
    this->vida = vida;
    this->mana = mana;
    this->forca = forca;
    this->magia = magia;
    this->resFisico = resFisico;
    this->resMagia = resMagia;
    this->agilidade = agilidade;
}

void Personagem::imprimeDados(){
    cout << vida << " - " << mana << " - " << forca << " - " << magia << " - ";
    cout << resFisico << " - " << resMagia << " - " << agilidade;
}

int main(){
    Personagem *guerreiro = new Personagem (4000,30,100,20,80,20,20);
    guerreiro -> imprimeDados();
    return 0;
}