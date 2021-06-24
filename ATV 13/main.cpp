#include "classe.h"
#include "accessdata.h"
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <time.h>
using namespace std;

Accessdata::Accessdata(int qtdAtributos) {
    //você deverá retorar este vetor de atributos para dentro do seu programa no momento de instanciar um novo personagem
    this->qtdAtributos = qtdAtributos;
    this->atributos = new int [qtdAtributos];    //quantidade de atributos das classes do jogo
}
string Accessdata::abreArquivo (string nomeDaClasse) {
    fstream arq;
    arq.open(nomeDaClasse ,ios::in);
    string linha;
    
    //Faz a leitura linha a linha do arquivo texto (string linha armazena a linha lida do arquivo)
    if (arq.is_open()){ 
        getline(arq, linha);       
    }
    arq.close();
    return linha;
}
int * Accessdata::obtemAtributos (string nomeDaClasse){    
    string linha = abreArquivo (nomeDaClasse);
    char str[linha.size()];
    //converte a string para um vetor de caractere          
    for (int i = 0; i < linha.size(); i++)        
        str[i] = linha[i];
    char ch[2] = ",";   //especifica o caractere que será usado para dividir a string (split)    
    char *token;
    char *palavra;
    int i = 0; 

    token = strtok(str, ch);     
    while( token != NULL ) {
        palavra = token;
        token = strtok(NULL, ch);
        this->atributos[i++] = atoi(palavra);
    }
    return this->atributos;         
}

Arma::Arma(int vetor[4]){
    this->nome = vetor[0];
    this->id = vetor[1];
    this->danoMin = vetor[2];
    this->danoMax = vetor[3];
}
void Arma::imprimeDados(){
    cout << nome << " - " << id << " - " << danoMin << " - " << danoMax << " - "; 
}

int Arma::calculaDano(){
    int dano = this->danoMin + (rand() % (this->danoMax - this->danoMin));
    return dano;
}

Personagem::Personagem(int vetor[7])
{
    this->vida = vetor[0];
    this->mana = vetor[1];
    this->forca = vetor[2];
    this->magia = vetor[3];
    this->resFisico = vetor[4];
    this->resMagia = vetor[5];
    this->agilidade = vetor[6];

    Accessdata * a = new Accessdata(4);    
    int * atributos = a->obtemAtributos ("2porrete.txt");
    arma = new Arma(atributos);
}
void Personagem::imprimeDados()
{
    cout << vida << " - " << mana << " - " << forca << " - " << magia << " - ";
    cout << resFisico << " - " << resMagia << " - " << agilidade << "\n";
}

int Personagem::mostraVida(){
    return vida;
}
int Personagem::mostraMana(){
    return mana;
}

int Personagem::ataqueFisico(){
    float dano = arma->calculaDano();
    dano += dano * (this->forca * 0.01);
    return dano;
}

int Personagem::esquiva(){
    int base = rand() % 100 + 1;
    if (base < this->agilidade)
        return 1;
    return 0;
}

void Personagem::recebeDano(int dano, int flag){

    if(flag == 1){
        //cout << dano << "\n";
        dano -= dano * (this->resFisico * 0.01);
        //cout << dano << "\n";
    }
    else if(flag == 2){

    }
    else{
        cout << "Como voce conseguiu fazer isso?!? E serio, como??";
    }
    //cout << this->vida << "\n";
    this->vida -= dano;
    //cout << this->vida << "\n";
}

int observaVida(int vida){
    if (vida <= 0)
        return 1;
    return 0;
}

int menuCombate(int i, Personagem *playerX, Personagem *playerY)
{
    int op, stop, dano, base;
    do
    {
        stop = 1;
        cout << "\n [JOGADOR " << i << "] - HP: " << playerX->mostraVida() << " MP: " << playerX->mostraMana() << " \n Escolha: \n 1-Ataque Fisico  |  2-Magia  |  3-Trocar arma \n --";
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            dano = playerX->ataqueFisico();
            if(playerY->esquiva()){
                cout << "Esquiva!! \n ";
            }
            else
                playerY->recebeDano(dano, 1);
            return 1;
            break;
        case 2:
            
            return 2;
            break;
        case 3:
            return 3;
            break;
        default:
            cout << "Inválido \n";
            stop = 0;
            break;
        }
    } while (stop == 0);
    return 0;
}



int main()
{
    srand (time(0));
    //Definir atributos de personagens
    int q = 7;
    Accessdata * a = new Accessdata(q);    
    int * atributos;  
    //Definir variáveis
    int op, i, n, stop;
    int teste[2][q];
    Personagem *player1;
    Personagem *player2;
    //Escolher personagens
    for (i = 1; i <= 2; i++)
    {
        do
        {
            stop = 1;
            cout << "Jogador " << i << "\nEscolha seu personagem: \n 1-Guerreiro \n 2-Ladrao \n 3-Mago \n 4-Paladino \n 5-Animal \n 6-Troll \n 7-Dragao \n 8-Zumbi \n --";
            scanf("%d", &op);
            getchar();
            switch (op)
            {
            case 1:
                atributos = a->obtemAtributos ("1guerreiro.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 2:
                atributos = a->obtemAtributos ("1ladrao.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 3:
                atributos = a->obtemAtributos ("1mago.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 4:
                atributos = a->obtemAtributos ("1paladino.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 5:
                atributos = a->obtemAtributos ("1animal.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 6:
                atributos = a->obtemAtributos ("1troll.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 7:
                atributos = a->obtemAtributos ("1dragao.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            case 8:
                atributos = a->obtemAtributos ("1zumbi.txt");
                for (n = 0; n < 7; n++)
                    teste[i][n] = atributos[n];
                break;
            default:
                cout << "Opcao invalida, tente novamente\n";
                stop = 0;
                break;
            }
        } while (stop == 0);
    }
    player1 = new Personagem(teste[1]);
    player2 = new Personagem(teste[2]);
    //player1->imprimeDados();
    //player2->imprimeDados();
    delete teste;
    delete a;
    delete atributos;
    // Rodadas
    cout << "Preprarem-se para a batalha \n COMECAR \n";
    stop = 0;
    do
    {
        //turno Player 1
        if(stop == 0){
            op = menuCombate(1, player1, player2);
            if (observaVida(player2->mostraVida())){
                cout << "TEMOS UM VENCEDOR!!! \n Jogador 1 vence a partida. \n";
                stop = 1;
            }
        }
        
        //turno Player 2
        if (stop == 0){
            op = menuCombate(2, player2, player1);
            if (observaVida(player1->mostraVida())){
                cout << "TEMOS UM VENCEDOR!!! \n Jogador 2 vence a partida. \n";
                stop = 1;
            }
        }
        
        
    } while (stop == 0);

    return 0;
}