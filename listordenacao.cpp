#include<iostream>
#include<list>

using namespace std;

void moveParaLista3(list<int>& lista3, list<int>& listaSelecionada){
    lista3.push_back(listaSelecionada.front());
    listaSelecionada.pop_front();
}

int main(){

	list<int> lista1; //ponterio para lista um
    list<int> lista2; //ponterio para lista dois
    list<int> lista3; //ponterio para lista tres
    int x; //variavel auxiliar para leitura e escrita

    while(x!=0){
        cin >> x;
        if(x == 0 ) break;
        lista1.push_back(x);
    }
    x=1;
    while(x!=0){
        cin >> x;
        if(x == 0 ) break;
        lista2.push_back(x);
    }



    //Ordenando
    while(!lista1.empty() || !lista2.empty()){
        if (*lista1.begin() < *lista2.begin()) moveParaLista3(lista3, lista1);
        else moveParaLista3(lista3, lista2);
    }

    cout<<"Fora do While\n\n\n";
    if(lista1.empty()){
        while(!lista2.empty()) moveParaLista3(lista3, lista2);
    }
    else{
        while(!lista1.empty()) moveParaLista3(lista3, lista1);
    }

    while(!lista3.empty()){
        cout << lista3.front() << " ";
        lista3.pop_front();
    }
    cout << endl;

    return 0;

}