#include <iostream>
#include <cmath>
#include <math.h>

//Algoritmo para ordenação vetorial

using namespace std;

void quickSort(int vetor[], int tamanho, int i, int j)
{
    int trab,esq,dir,pivo;
    esq = i;
    dir = j;
    
    pivo = vetor[(int)round((esq + dir)/2.0)];
    do
    {
        while (vetor[esq] < pivo)
            esq++;
        while (vetor[dir] > pivo)
            dir--;

        if (esq <= dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    }while (esq <= dir);

    if (dir-i >= 0)
        quickSort(vetor,tamanho,i,dir);
    if (j-esq >= 0)
        quickSort(vetor,tamanho,esq,j);
    }

int main(){

    int V[1000]; //armazeno os dados
    int tamanho; //numero de elementos
    int i, j; 
    int K; //contador

    //Lendo o tamanho do vetor
    cin >> tamanho;

    //Lendo vetor
    for (K=0;K<tamanho;K++)
        cin >> V[K];

    //Mostrando o vetor antes da ordenação
    for (K=0;K<tamanho;K++)
        cout << V[K] << " ";
    cout << endl;

    //Chamando função de ordenação
    i = 0;
    j = tamanho - 1;
    quickSort(V,tamanho,i,j);

    //Mostrando resultado
    for (K=0;K<tamanho;K++)
        cout << V[K] << " ";
    cout << endl;


    return 0;

}