#include<iostream>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador
    int menor;

    cin >> N;

    p = &v[0];

    for(i=0;i<N;i++){
        cin >> v[i];   
    }
    
    menor = p[0];
    for(i=1;i<N;i++){
        if(p[i]<p[i-1])
            menor = p[i];
    }

    cout << menor << endl;
       
    return 0;
}