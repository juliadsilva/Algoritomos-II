#include<iostream>
#include<list>

using namespace std;

void moveEstoqueParaVenda(list<int>& listaEstoque, list<int>& listaVenda){
   
    
    listaVenda.push_back(listaEstoque.front());
    listaEstoque.pop_front();
    
}

int main(){

	list<int> listaEstoque; //lista do estoque
    list<int> listaVenda; //lista das prateliras
    int qtdOperacao; //quantidade de operações
    int indiceOperacao; //contador
    int operacao; //operação
    int codPorduto; //codigo do produto

    //Lendo a quantidade de operação
    cin >> qtdOperacao;

    for (indiceOperacao=0; indiceOperacao<qtdOperacao; indiceOperacao++){
        //Lendo a operação
        cin >> operacao;

        switch(operacao){
            case 1: 
                cin >> codPorduto; 
                listaEstoque.push_back(codPorduto);
                break;
            case 2:
                moveEstoqueParaVenda(listaEstoque, listaVenda);
                break;
        }
    }
    
    //Removendo elementos Estoque
    cout<<"Estoque: ";
    while(!listaEstoque.empty()){
        cout << *listaEstoque.begin() << " ";
        listaEstoque.pop_front();
    }
    cout<<endl;

    //Removendo elementos Estoque
    cout<<"Venda: ";
    while(!listaVenda.empty()){
        cout << listaVenda.back() << " ";
        listaVenda.pop_back();
    }
    cout<<endl;

}