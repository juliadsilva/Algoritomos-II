#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

//Algoritmo para correção de prova de multipla escolha

using namespace std;

int main(){

    char gabarito[10]; //auxiliar de leitura do gabarito da prova
    string gab[10]; //gabarito da prova
    char respostas[10]; //auziliar de leitura das respostas do aluno
    string resp[10]; //respostas do aluno
    string *g; //ponteiro para o gabarito
    string *r; //ponteiro para a resposta
    int corretas; //contador das respostas corretas
    int i;//contador

    corretas = 0;

    //Atricuindo ponteiros
    g = &gab[0];
    r = &resp[0];

    //Lendo o gabarito
    for(i=0;i<10;i++){
        cin >> gabarito; 
        gab[i] = gabarito;
    }

    //Lendo as respostas
    for(i=0;i<10;i++){
        cin >> respostas; 
        resp[i] = respostas;
    }       
      
    //Comparando gabarito e respostas
    for(i=0;i<10;i++) {
       if (g[i] == r[i]){
            corretas ++;
        }
    }

    //Mostrando a quantida de respostas corretas
    cout << corretas << endl;
       
    return 0;
}