#include<iostream>

using namespace std;

int main(){

    int N; //numero de elementos no vetor
    int v[100]; //vetor
    int *p; //ponteiro
    int i; //contador
    double media;

    cin >> N;

    p = &v[0];

    for(i=0;i<N;i++){
        cin >> v[i];   
    }
    
    for(i=0;i<N;i++){
        media = media + p[i];
    }

    cout<<fixed;
    cout.precision(2);
    cout << media/N << endl;
       
    return 0;
}