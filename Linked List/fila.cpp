#include<iostream>
#include<list>

using namespace std;

int main(){

	list<int> fila; //ponterio para
	int i; //contador
    int x; //variavel auxiliar para leitura e escreita

    for(i=0;i<4;i++){
        cin >> x;
        fila.push_back(x);
    }

    //Removendo elementos e inserindo
    while(!fila.empty()){

        x = *fila.begin();
        cout << x << " ";
        fila.pop_front();
    }

    return 0;

}