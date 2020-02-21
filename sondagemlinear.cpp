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


int hash1(int k, int i, int m){

    int posicao;

    posicao = (hash_aux(k,m)+i) % m; 
    return posicao;

}

int main(){

    int m; //tamanho do vetor
    int k; //chave
    int i; //contador
    int posicao; //retorno da função

    //Lendo valores
    cin >> k >> m;

    for(i=0;i<m;i++){
        posicao = hash1(k,i,m);
        cout << posicao << " ";
    }
    cout << endl;

    return 0;
}

    