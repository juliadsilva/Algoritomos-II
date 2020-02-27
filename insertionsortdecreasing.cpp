#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
    int k,j; // contadores
    int chave;
    for (j=1;j<tamanho;j++)
    {
        chave = vetor[j];
        k = j-1;
        while ((k >= 0) && (vetor[k] < chave))
        {
            vetor[k+1] = vetor[k];
            k = k-1;
        }
        vetor[k+1] = chave;
    }
}

int main (){
    
    int vetor [100]; 
    int X; // variavel auxilar
    int i; // tamanho do vetor
    int j; // contador
    
    //Lendo elementos do vetor
    i=0;
    cin >> X;
    while (X != 0){
        vetor[i] = X;
        i++;
        cin >> X;
    }

    //Ordenando o vetor
    insercaoDireta(vetor, i);

    //Mostrando o vetor ordernado
    for (j=0;j<i;j++)
        cout << vetor[j] << " ";
    cout << endl;

    return 0;
}    