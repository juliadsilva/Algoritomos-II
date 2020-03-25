#include<iostream>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador
    int maior;

    cin >> N;

    p = &v[0];

    for(i=0;i<N;i++){
        cin >> v[i];   
    }
    
    maior = p[0];
    for(i=1;i<N;i++){
        if(p[i]>p[i-1])
            maior = p[i];
    }

    cout << maior << endl;
       
    return 0;
}