#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador
    int nelementos = 0; //

    //Lendo o numero de elementos
    cin >> N;

    //Entrada de dados
    for(i=0;i<N;i++){
        cin >> v[i];   
    }
    
    p = v; // A variavel ponteiro p aponta para o primeiro elemento do vetor
    
    //Processamento    
    for(i=0;i<N;i++){
        if(*p %3 == 0 ){
            nelementos++;
        }  
        p++;  
    }

    //Saida de dados
    cout << nelementos << endl;
    
    return 0;
}