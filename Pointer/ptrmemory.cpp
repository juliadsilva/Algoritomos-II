#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int *p; //ponteiro para int
    int i; //contador
    int maior = INT_MIN; 
    int numero; //maior numero par

    //Lendo o numero de elementos
    cin >> N;

    //Alocando memoria
    p = new int [N];
    
    //Entrada de dados
    for(i=0;i<N;i++){
        cin >> p[i];   
    }

    //Processamento    
    for(i=0;i<N;i++){
        if(p[i] > maior && p[i]%2 == 0){
            numero = p[i]; 
            maior = p[i];
        }
    }

    //Saida de dados
    cout << numero;

    //Liberando memoria
    delete [] p;
    
    return 0;
}