#include <iostream>

using namespace std;

int main (){

    int V[5];
    int X;
    int A;

    // Lendo 5 numeros e armazenando em um vetor
    for(int i=0;i<5;i++)
    cin >> V[i];
   
    // Lendo X
    cin >> X;

    // Verificando se x está ou não no vetor
    A=0;
    for (int i=0;i<5;i++)
    {
        if(X == V[i])
            A=1;
        else
            A=0;
    }

    // Mostrado os resultados
    if(A == 1)
        cout << "Esta no vetor" << endl;
    else
        cout << "Nao esta no vetor" << endl;

    return 0;
}
