#include <iostream>
#include <cmath>

//Algortimo para calculo de potencia 

using namespace std;

//Funcao para calcular a elevado a n
int pot(int a, int n){
    if (n == 0)
        return 1;
    else 
        return a*pot(a,n-1);
}

int main (){

    int a; //numero
    int n; //potencia
    int r; //resultado

    //Entrada dos valores
    cin >> a >> n;

    //Chamando a funcao
    r = pot(a,n);
    
    //Mostrado resultado
    cout << r << endl;

    return 0;
}
