#include<iostream>
#include<list>

using namespace std;

int soma(list<int> lista){

    list<int> :: iterator it; //interator para varrer a lista
    int somap; 

    somap = 0;

    for(it = lista.begin(); it!=lista.end();it++){
        somap  += *it;
    }
    return somap;
}

int main(){

	list<int> lista; //ponterio para lista
    int x; //variavel auxiliar para leitura e escrita
    int somat; //Retorno da função
  
    //Lendo elementos e inserindo na fila
    cin >> x;
    while (x!=0)
    {   
        lista.push_back(x);
        cin >> x;
    }

    //Chamado a função com resultado
    somat = soma(lista);

    //Mostrando resultado
    cout << somat << endl;

    return 0;

}