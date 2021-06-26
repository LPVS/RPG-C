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

//Classe Accesdata
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

//Atributos Arma
Arma::Arma(int vetor[4]){
    this->id = vetor[1];
    this->danoMin = vetor[2];
    this->danoMax = vetor[3];
    this->nome = obtemNome(vetor[1]);
}
void Arma::imprimeDados(){
    cout << nome << " - " << id << " - " << danoMin << " - " << danoMax << " - "; 
}
int Arma::calculaDano(){
    //cout << this->danoMin << " - " << this->danoMax << " \n ";
    int dano = this->danoMin + (rand() % (this->danoMax - this->danoMin));
    return dano;
}
int Arma::obtemID(){
    return id;
}
string Arma::obtemNome(int id){
    string base;
    if (id == 0){
        base = "Desarmado";
    }
    else if(id == 1){
        base = "Garra Letal";
    }
    else if(id == 2){
        base = "Tridente Sagrado";
    }
    else if(id == 3){
        base = "Espada Barroca";
    }
    else if(id == 4){
        base = "Porrete";
    }
    else if(id == 5){
        base = "Cajado";
    }
    else if(id == 6){
        base = "Besta";
    }
    else if(id == 7){
        base = "Esfera de Ataque";
    }
    else if(id == 8){
        base = "Voto Solene de BulKathos";
    }
    return base;
}
void Arma::imprimeArma(int vetor[4]){
    for (int i = 0; i < 4; i++)
    {
        if (vetor[i] == 1)
            cout << "- 1 Garra Letal - ";
        else if (vetor[i] == 2)
            cout << "- 2 Tridente Sagrado - ";
        else if (vetor[i] == 3)
            cout << "- 3 Espada Barroca - ";
        else if (vetor[i] == 4)
            cout << "- 4 Porrete - ";
        else if (vetor[i] == 5)
            cout << "- 5 Cajado - ";
        else if (vetor[i] == 6)
            cout << "- 6 Besta - ";
        else if (vetor[i] == 7)
            cout << "- 7 Esfera de Ataque - ";
    }
}

//Atributos Personagem
Personagem::Personagem(int vetor[11])
{
    this->vida = vetor[0];
    this->mana = vetor[1];
    this->forca = vetor[2];
    this->magia = vetor[3];
    this->resFisico = vetor[4];
    this->resMagia = vetor[5];
    this->agilidade = vetor[6];
    for(int i = 0; i < 4; i++){
        this->idArma[i] = vetor[(7+i)];
    }
    Accessdata * a = new Accessdata(4);    
    int * atributos = a->obtemAtributos ("2desarmado.txt");
    arma = new Arma(atributos);
    //arma->imprimeDados();
    delete a;
    delete atributos;
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
        //cout << dano << "\n";
        dano -= dano * (this->resMagia * 0.01);
        //cout << dano << "\n";
    }
    else{
        cout << "Como voce conseguiu fazer isso?!? E serio, como??";
    }
    cout << " [Dano causado: " << dano << "] \n";
    //cout << this->vida << "\n";
    this->vida -= dano;
    //cout << this->vida << "\n";
}
int Personagem::trocarArma(){

    string base;
    Accessdata * a = new Accessdata(4);    
    int * atributos, op, stop;

    cout << " \n [Escolha sua nova arma] \n ";
    arma->imprimeArma(idArma);
    do
    {
        scanf("%d", &op);
        getchar();
        stop = 0;
        for(int i = 0; i < 4; i++){
            if (idArma[i] != op)
                stop++;
        }
        if(stop == 4)
            cout << "[Opcao Invalida, escolha novamente] \n";
    } while (stop == 4);

    switch (op)
    {
        case 1:
            base = "2garra-letal.txt";
            break;
        case 2:
            base = "2tridente-sagrado.txt";
        break;
        case 3:
            base = "2espada-barroca.txt";
        break;
        case 4:
            base = "2porrete.txt";
        break;
        case 5:
            base = "2cajado.txt";
        break;
        case 6:
            base = "2besta.txt";
        break;
        case 7:
            base = "2esfera-de-ataque.txt";
        break;
        default:
            cout << "Erro: Opcao invalida";
            break;
    } 
    //arma->imprimeDados();
    atributos = a->obtemAtributos (base);
    arma = new Arma(atributos);
    //arma->imprimeDados();
    cout << " \n [Voce trocou sua arma para: " << arma->obtemNome(op) << "] \n ";
    return 0;
}

//Funções Gerais

int observaVida(int vida){
    if (vida <= 0)
        return 1;
    return 0;
}

void menuCombate(int i, Personagem *playerX, Personagem *playerY)
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
            if(playerY->esquiva())
                cout << "Esquiva!! \n ";
            else
                playerY->recebeDano(dano, 1);
            break;
        case 2:
            
            break;
        case 3:
            playerX->trocarArma();
            break;
        default:
            cout << "Inválido \n";
            stop = 0;
            break;
        }
    } while (stop == 0);
}



int main()
{
    srand (time(0));
    //Definir atributos de personagens
    int q = 11;
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
            cout << " \n Jogador " << i << "\nEscolha seu personagem: \n 1-Guerreiro \n 2-Ladrao \n 3-Mago \n 4-Paladino \n 5-Animal \n 6-Troll \n 7-Dragao \n 8-Zumbi \n --";
            scanf("%d", &op);
            getchar();
            switch (op)
            {
            case 1:
                atributos = a->obtemAtributos ("1guerreiro.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 2:
                atributos = a->obtemAtributos ("1ladrao.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 3:
                atributos = a->obtemAtributos ("1mago.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 4:
                atributos = a->obtemAtributos ("1paladino.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 5:
                atributos = a->obtemAtributos ("1animal.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 6:
                atributos = a->obtemAtributos ("1troll.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 7:
                atributos = a->obtemAtributos ("1dragao.txt");
                for (n = 0; n < q; n++)
                    teste[i][n] = atributos[n];
                break;
            case 8:
                atributos = a->obtemAtributos ("1zumbi.txt");
                for (n = 0; n < q; n++)
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
    delete a;
    delete atributos;
    // Rodadas
    cout << "Preprarem-se para a batalha \n COMECAR \n";
    stop = 0;
    do
    {
        //turno Player 1
        if(stop == 0){
            menuCombate(1, player1, player2);
            if (observaVida(player2->mostraVida())){
                cout << "TEMOS UM VENCEDOR!!! \n Jogador 1 vence a partida. \n";
                stop = 1;
            }
        }
        
        //turno Player 2
        if (stop == 0){
            menuCombate(2, player2, player1);
            if (observaVida(player1->mostraVida())){
                cout << "TEMOS UM VENCEDOR!!! \n Jogador 2 vence a partida. \n";
                stop = 1;
            }
        }
        
    } while (stop == 0);

    return 0;
}