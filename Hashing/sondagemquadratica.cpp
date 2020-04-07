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

int hash1(int k, int i, int m, int c1, int c2){

    int posicao;
    int X; //variavel auxiliar;

    X = (c1*i)+(c2*i*i);
    posicao = (hash_aux(k,m)+X) % m; 
    return posicao;

}

int main(){

    int m; //tamanho do vetor
    int k; //chave
    int i; //contador
    int c1, c2; //constantes
    int posicao; //retorno da função

    //Lendo valores
    cin >> k >> m >> c1 >> c2;
    
    //Chamando a função e mostrando resultados
    for(i=0;i<m;i++){
        posicao = hash1(k,i,m,c1,c2);
        cout << posicao << " ";
    }
    cout << endl;

    return 0;
}

    