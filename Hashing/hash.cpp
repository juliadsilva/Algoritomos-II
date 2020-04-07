#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int hash_aux(int k, int m){

    int resultado; //retorno da função

    resultado = k % m; //k mod m

    if (resultado < 0)
        return resultado+m;
    else return resultado;    
}

int main(){

    int m; //tamanho do vetor
    int k; //chave
    int i; //contaodor
    int j; //contador
    int resultado; //retorno da função

    //Lendo valores até m=0 e k=0;
    i=0;
    cin >> k >> m;

    while (m != 0 && k != 0){
        resultado = hash_aux(k,m); 
        cout << resultado << endl;
        cin >> k >> m;
    }

    return 0;
}

    