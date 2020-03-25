#include<iostream>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador

    //Lendo o numero de elementos
    cin >> N;

    p = &v[0];

    for(i=0;i<N;i++){
        cin >> p[i];   
    }
    
    for(i=0;i<N;i++){
        cout << v[i] << " ";       
    }
    cout << endl;
    
    return 0;
}