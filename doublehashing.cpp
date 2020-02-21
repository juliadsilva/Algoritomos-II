#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int h1(int k, int m){

    int h1; //retorno da função

    h1 = k % m; //k mod m
    if (h1 < 0) 
        return h1+m;
    else return h1;    
}

int h2(int k, int m){

    int h2; //retorno da função
    int a, b; //variaveis auxiliares

    a = m-1;
    b = k % a;
    h2 = 1 + b; 
    
    return h2;
   
}

int hash1(int k, int m, int i){

    int posicao;
    int X; //Variavel auxiliar
    
    X = h1(k,m) + i*h2(k,m);
    cout << "i" << i << endl;
    cout << "x" << X << endl;
    posicao = X % m;
   
    return posicao; 

}

int main(){

    int m; //tamanho do vetor
    int k; //chave
    int i; //contador
    int posicao; //retorno da função

    //Lendo valores
    cin >> k >> m;
    
    //Chamando a função e mostrando resultados
    for(i=0;i<m;i++){
        posicao = hash1(k,m,i);
        cout << posicao << " ";
    }
    cout << endl;

    return 0;
}

    