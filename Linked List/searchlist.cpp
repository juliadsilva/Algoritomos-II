#include<iostream>
#include<list>

using namespace std;

int main(){

	list<int> fila; //ponterio para
    list<int> :: iterator it; //interator para varrear a lista
    int x; //variavel auxiliar para leitura e escreita
    int proc; //elemento a ser procurado
    bool achou = false; //true se achar 

    //Lendo elemeentos e inserindo na fila
    cin >> x;
    while (x!=0)
    {
        fila.push_back(x);
        cin >> x;
    }

    //Lendo elemento a ser procurado
    cin >> proc;

    //Verificandp se proc está na fila
    achou = false;
    for (it=fila.begin() ; it!=fila.end();it++){
        if(*it == proc)
            achou = true;
    }

    if(achou)
        cout << "Encontrado" << endl;
    else 
        cout << "Nao encontrado" << endl;

    return 0;

}