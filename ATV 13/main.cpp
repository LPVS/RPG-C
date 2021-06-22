#include "classe.h"
#include <iostream>
#include <string.h>
using namespace std;

Personagem::Personagem(int vetor[7])
{
    this->vida = vetor[0];
    this->mana = vetor[1];
    this->forca = vetor[2];
    this->magia = vetor[3];
    this->resFisico = vetor[4];
    this->resMagia = vetor[5];
    this->agilidade = vetor[6];
}

void Personagem::imprimeDados()
{
    cout << vida << " - " << mana << " - " << forca << " - " << magia << " - ";
    cout << resFisico << " - " << resMagia << " - " << agilidade << "\n";
}

void testando(int vetor[7]){
    for(int i = 0; i< 7;i++)
        cout << vetor[i] << " - ";
}


int main()
{
    //Definir personagens
    int q = 7;
    int guerreiro[q] = {4000, 30, 100, 20, 80, 20, 20};
    int ladrao[q] = {2800, 50, 50, 30, 40, 50, 80};
    int mago[q] = {2500, 100, 40, 100, 30, 80, 40};
    int paladino[q] = {3200, 80 ,60, 50, 60, 60, 60};
    int animal[q] = {3200,30,80,20,80,20,50};
    int troll[q] = {2800,20,100,20,80,20,20};
    int dragao[q] = {3000,40,100,20,50,50,30};
    int zumbi[q] = {2500,20,40,20,40,80,50};

    //Definir variáveis
    int op, i, n, stop;
    int teste[2][q];
    Personagem *player1;
    Personagem *player2;
    //Escolher personagens
    for ( i = 1; i <= 2; i++)
    {
        do
        {
            stop = 1;
            cout << "Jogador " << i << "\nEscolha seu personagem: \n 1-Guerreiro \n 2-Ladrao \n 3-Mago \n 4-Paladino \n 5-Animal \n 6-Troll \n 7-Dragao \n 8-Zumbi \n --";
            scanf("%d", &op);
            getchar();
            cout << op << "\n";
            switch (op)
            {
            case 1:
                for (n = 0; n < 7; n++)
                    teste[i][n] = guerreiro[n];
                break;
            case 2:
                for (n = 0; n < 7; n++)
                    teste[i][n] = ladrao[n];
                break;
            case 3:
                for (n = 0; n < 7; n++)
                    teste[i][n] = mago[n];
                break;
            case 4:
                for (n = 0; n < 7; n++)
                    teste[i][n] = paladino[n];
                break;
            case 5:
                for (n = 0; n < 7; n++)
                    teste[i][n] = animal[n];
                break;
            case 6:
                for (n = 0; n < 7; n++)
                    teste[i][n] = troll[n];
                break;
            case 7:
                for (n = 0; n < 7; n++)
                    teste[i][n] = dragao[n];
                break;
            case 8:
                for (n = 0; n < 7; n++)
                    teste[i][n] = zumbi[n];
                break;
            default:
                cout << "Opcao invalida, tente novamente\n";
                stop = 0;
                break;
            }
        } while (stop == 0);
    }
    return 0;
}