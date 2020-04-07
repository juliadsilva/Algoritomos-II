#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
    int i,j; // contadores
    int chave;
    for (j=1;j<tamanho;j++)
    {
        chave = vetor[j];
        i = j-1;
        while ((i >= 0) && (vetor[i] > chave))
        {
            vetor[i+1] = vetor[i];
            i = i-1;
        }
        vetor[i+1] = chave;
    }
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

    //Ordenando o vetor
    insercaoDireta(vetor, N);

    //Mostrando o vetor ordernado
    for (i=0;i<N;i++)
        cout << vetor[i] << " ";
    cout << endl;

    return 0;
}    