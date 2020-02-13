#include <iostream>
#include <cmath>

using namespace std;

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

    cin >> a >> n;

    r = pot(a,n);

    cout << r << endl;

    return 0;
}
