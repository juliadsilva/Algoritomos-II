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
    list<int> :: iterator it1; //interator para varrear a lista um
    list<int> :: iterator it2; //interator para varrear a lista dois
    int x; //variavel auxiliar para leitura e escrita
    int tamanholista3;
    int contador = 0; 
    int contador1 = 0; 
    int contador2 = 0; 

    cin >> x;
    while(x!=0){
        lista1.push_back(x);
        cin >> x;
    }

    cin >> x;
    while(x!=0){
        lista2.push_back(x);
        cin >> x;
    }

    tamanholista3 = lista1.size() + lista2.size();
   
    it1 = lista1.begin();
    it2 = lista2.begin();

    while((contador1 < lista1.size()) && (contador2 < lista2.size())){        

        if (*it1 < *it2){
            lista3.push_back(*it1);           
            it1++;                
            contador1++;
        }
        else{
            lista3.push_back(*it2);
            it2++; 
            contador2++;
        } 

    }

    if(contador1 == lista1.size()){
        while(contador2 < lista2.size()){
        lista3.push_back(*it2);
            it2++; 
            contador2++;
        }
    }

    if(contador2 == lista2.size()){
        while(contador1 < lista1.size()){
        lista3.push_back(*it1);
            it1++; 
            contador1++;
        }
    }

    while(!lista3.empty()){
        cout << lista3.front() << " ";
        lista3.pop_front();
    }
    cout << endl;

    return 0;

}