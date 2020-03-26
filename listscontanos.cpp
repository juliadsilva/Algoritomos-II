#include<iostream>
#include<list>

using namespace std;

int contador(list<int> lista){

    list<int> :: iterator it; //interator para varrer a lista
    int cont;

    cont = 0;

    for(it = lista.begin(); it!=lista.end();it++){
        cont ++;
    }

    return cont;
}


int main(){

	list<int> lista; //ponterio para lista
    int x; //variavel auxiliar para leitura e escrita
    int elementos; //Retorno da função
  
    //Lendo elementos e inserindo na fila
    cin >> x;
    while (x!=0)
    {   
        lista.push_back(x);
        cin >> x;
    }

    //Chamado a função com resultado
    elementos = contador(lista);

    //Mostrando resultado
    cout << elementos << endl;

    return 0;

}