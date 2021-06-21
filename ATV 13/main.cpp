#include "classe.h"
#include <iostream>
using namespace std;

Personagem::Personagem(int vida, int mana, int forca, int magia, int resFisico, int resMagia, int agilidade)
{
    this->vida = vida;
    this->mana = mana;
    this->forca = forca;
    this->magia = magia;
    this->resFisico = resFisico;
    this->resMagia = resMagia;
    this->agilidade = agilidade;
}

void Personagem::imprimeDados()
{
    cout << vida << " - " << mana << " - " << forca << " - " << magia << " - ";
    cout << resFisico << " - " << resMagia << " - " << agilidade;
}

int main()
{
    //Definir personagens
    Personagem *guerreiro = new Personagem(4000, 30, 100, 20, 80, 20, 20);
    Personagem *ladrao = new Personagem(2800, 50, 50, 30, 40, 50, 80);
    Personagem *mago = new Personagem(2500, 100, 40, 100, 30, 80, 40);
    Personagem *paladino = new Personagem(3200, 80 ,60, 50, 60, 60, 60);
    Personagem *animal = new Personagem(3200,30,80,20,80,20,50);
    Personagem *troll = new Personagem(2800,20,100,20,80,20,20);
    Personagem *dragao = new Personagem(3000,40,100,20,50,50,30);
    Personagem *zumbi = new Personagem(2500,20,40,20,40,80,50);

    //Definir variáveis
    int op, stop;
    int *teste;

    //Escolher personagens
    for (int i = 1; i <= 2; i++)
    {
        do
        {
            stop = 1;
            cout << "Jogador " << i << "\nEscolha seu personagem: \n 1-Guerreiro \n 2-Ladrao \n 3-Mago \n 4-Paladino \n --";
            scanf("%d", &op);
            getchar();
            cout << op << "\n";
            switch (op)
            {
            case 1:
                
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            /*
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                
                break;
            case 8:
                
                break;
            */
            default:
                cout << "Opcao invalida, tente novamente\n";
                stop = 0;
                break;
            }
        } while (stop == 0);
    }
    return 0;
}