#include<iostream>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador
    int pp; //par e positivo

    cin >> N;

    p = v; // A variavel ponteiro p aponta para o primeiro elemento do vetor

    for(i=0;i<N;i++){
        cin >> v[i];   
    }

    for(i=0;i<N;i++){
        if((*p%2 == 0) && (*p > 0))
          pp++;  
        p++
    }

    cout << pp << endl;
       
    return 0;
}