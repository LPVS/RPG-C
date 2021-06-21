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
    int op[2], stop;
    for (int i = 1; i <= 2; i++)
    {
        stop = 0;
        do
        {
            cout << "Jogador " << i << "\nEscolha seu personagem: \n 1-Guerreiro \n 2-Ladrao \n 3-Mago \n 4-Paladino \n --";
            scanf("%d", &op[i]);
            getchar();
            switch (op[i])
            {
            case 1:
                
                break;
            case 2:
                /* code */
                break;
            case 3:
                /* code */
                break;
            case 4:
                /* code */
                break;
            case 5:
                /* code */
                break;
            case 6:
                /* code */
                break;
            case 7:
                /* code */
                break;
            case 8:
                /* code */
                break;
            default:
                cout << "Opcao invalida, tente novamente\n";
                break;
            }
        } while (stop = 0);
    }
    /*
    //Definir personagens
    Personagem *guerreiro = new Personagem(4000, 30, 100, 20, 80, 20, 20);
    guerreiro->imprimeDados();
    return 0;
    */
}