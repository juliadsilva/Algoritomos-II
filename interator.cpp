#include<iostream>
#include<list>

using namespace std;

int main(){

	list<int> fila; //ponterio para
    list<int> :: iterator it; //interator para varrear a lista
	int i; //contador
    int x; //variavel auxiliar para leitura e escreita

    for(i=0;i<4;i++){
        cin >> x;
        fila.push_back(x);
    }

    //Entrada: 1 2 3 4
    it = fila.begin();
    cout << *it << endl;
    it++;
    cout<< *it << endl;

    return 0;

}