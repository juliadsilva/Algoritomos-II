#include <iostream>
#include <cmath>

/*Algortimo para combinação de grupos distintos com k pessoas
que podem ser formados a partir de n pessoas.*/


using namespace std;

//Funcao de combinação
int comb(int n, int k){
    if (k == 1)
        return n;
    else if(k==n)
        return 1;
    else 
        return comb(n-1,k-1) + comb(n-1,k);
}

int main (){

    int n; //numeros de pessoas
    int k; //quantidade de pessoas por combinacao
    int c; //resultado da combinacao

    //Entrada dos valores
    cin >> n >> k;

    //Chamando a funcao
    c = comb(n,k);
    
    //Mostrado resultado
    cout << c << endl;

    return 0;
}
