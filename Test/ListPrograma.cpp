#include<iostream>
#include<list>

using namespace std;

int main(){

	list<int> programa; //ponterio para lista
    list<int> :: iterator it; //interator para varrear a lista
	int n; //numero de progamas
    int x; //variavel auxiliar para leitura e escreita
    int i,j; //contador

    //Lendo o numero de programas
    cin >> n;

    //Lendo os nomes do programa e armazendo em uma lista
    for(i=0;i<n;i++){
        cin >> x;
        programa.push_back(x);
    }  

    //Rodando dois ciclos
    for(i=0;i<2;i++){
        it = programa.begin();
        for(j=0;j<n;j++){
            cout << *it << " ";
            it++;
        }
    }
    
    cout << endl;

    return 0;

}