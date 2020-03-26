#include<iostream>
#include<list>

using namespace std;

int main(){

	list<int> pilha; //ponterio para
	int i; //contador
    int x; //variavel auxiliar para leitura e escreita

    for(i=0;i<4;i++){
        cin >> x;
        pilha.push_front(x);
    }

    while(!pilha.empty()){

        x = *pilha.begin();
        cout << x << " ";
        pilha.pop_front();
    }

    return 0;

}