#include <iostream>

//Algoritmo para ordenação vetorial metodo bolha

using namespace std;

void bubbleSort(int vetor[], int tamanho)
{
    int i,j; // contadores
    int trab;
    bool troca;
    int limite;
    int contador=1; //quantas vezes a variável troca recebe o valor true.

    troca = true;
    limite = tamanho-1;

    while (troca)
    {
        troca = false;
        for (i=0;i<limite;i++)
        if (vetor[i] > vetor[i+1])
        {
            trab = vetor[i];
            cout << "New trab:" << trab << endl;
            vetor[i] = vetor[i+1];
            vetor[i+1] = trab;
            j = i;
            troca = true;
            contador ++;
        }
        limite = j;
    }
    cout << "Contador:" << contador << endl;
}

int main (){
    
    int vetor [100];
    int N;
    int i;

    //Lendo tamanho do vetor 
    cin >> N;

    //Lendo elementos do vetor
    for (i=0;i<N;i++)
        cin >> vetor[i];

    //Chamando funçao
    bubbleSort (vetor,N);
  
    return 0;
}    