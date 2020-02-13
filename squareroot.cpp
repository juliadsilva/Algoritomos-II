#include <iostream>
#include <cmath>
#include <math.h>

//Algoritmo para calculo de raiz quadrada

using namespace std;

/*Função que compara xo elevado quadrado com o numero da entrada (x),
  até que o erro entre eles seja menor que o erro de entrada*/

double raiz(int x, double xo, double erro){
   
    double x1; //modulo 

    x1 = fabs(xo*xo - x); //fabs é usado para retorna o modulo em double

    while (x1 > erro){

        xo = ((xo*xo)+x) / (2*xo);
        raiz (x,xo,erro);
        x1 = fabs(xo*xo - x);
    
    }

    return xo;
  
}

int main(){

    int x; //o número do qual se quer calcular a raiz
    double xo; //é uma estimativa inicial 
    double erro; //é um limitante superior para o erro
    double r; //resultado

    //Lendo valores de entrada
    cin >> x >> xo >> erro;

    //Chamando Funcao
    r  = raiz(x,xo,erro);

    //Mostrando resultado
    cout<<fixed;
    cout.precision(4);
    cout << r << endl;   
    
    return 0;
}