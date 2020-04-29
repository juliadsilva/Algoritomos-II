#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>

//Algoritmo para correção de prova de multipla escolha

using namespace std;

int main(){

    char gabarito[10]; //auxiliar de leitura do gabarito da prova
    char respostas[10]; //auziliar de leitura das respostas do aluno
    int corretas; //contador das respostas corretas
    int i;//contador
    char *pg, *pr; //ponteiros para varreas os vetores
  
    //Lendo o gabarito
    for(i=0;i<10;i++){
        cin >> gabarito[i]; 
    }

    //Lendo as respostas
    for(i=0;i<10;i++){
        cin >> respostas[i];
    }       
      
    //Comparando gabarito e respostas
    corretas = 0;
    pg = gabarito;
    pr = respostas;
    for(i=0;i<10;i++){
        if(*pg == *pr)
            corretas++;
        pg++;
        pr++;
    }

    //Mostrando a quantida de respostas corretas
    cout << corretas << endl;
       
    return 0;
}