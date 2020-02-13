#include <iostream>

using namespace std;

int funcao (int n){
    
    int i;
    int resp = 1;
    for (i=2;i<=n;i++)
        resp = resp * i;
    return resp;
}

int fatorial (int n){
    if (n == 0 )
        return 1;
    else
        return n*fatorial (n-1);   

}
int main (){

    int n;
    int r;
    cout << "Digite um numero inteiro: " << endl;
    cin >> n;

    r = fatorial (n);

    cout << "Resposta = " << r << endl;

    return 0;
}