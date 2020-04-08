#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int soma(int n, int &cont){
    
    cont ++;
    if (n == 0){
        return 0;
    }
    else{
        return n+soma(n-1,cont);  
    }
 
}
int main (){

    int numero; 
    int resultado; 
    int cont; //contador
    
    cout << "Digite um numero inteiro: " << endl;
    cin >> numero;

    cont = 0;
    
    resultado = soma(numero,cont);

    cout << "soma = " << resultado << endl;
    cout << cont << " chamadas recursivas" << endl;

    return 0;
}