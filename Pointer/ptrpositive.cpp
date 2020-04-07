#include<iostream>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador
    int pp; //par e positivo

    cin >> N;

    p = &v[0];

    for(i=0;i<N;i++){
        cin >> v[i];   
    }

    for(i=0;i<N;i++){
        if((p[i]%2 == 0) && (p[i] > 0))
          pp = pp + 1;  
    }

    cout << pp << endl;
       
    return 0;
}