#include<iostream>
#include<list>

using namespace std;

struct no
{
    int v; //vertice adjacente
    int peso; //peso da aresta
};

//Cria aresta do vertice u ao vertice v, com peso p
void cria_arestra(list<no>lista[], int u, int v, int p, int orientado)
{
    no aux; //vriavel auxiliar para inserir o no na lista

    aux.v = v;
    aux.peso = p;
    lista[u].push_back(aux);
    if(orientado==0)
    {
        aux.v = u;
        lista[v].push_back(aux);
    }
}
int main()
{
    list<no> lista[10]; //lista de adjacencias
    list<no>::iterator it; ///iterador para varrer a lista
    int u,v; //vertices de origem e destino, respesctivamente
    int p; //peso da aresta, se o grafo for ponderado
    int orientado; //um se for orientado, zero caso contrario    
    int nVertices; //numero de vertices do grafo
    int i; //contador
    
    //Lendo o numero de vertices do grafo
    cin >> nVertices;

    //Verificando se o grafo é orientado ou nao
    cin >> orientado;
   
    //Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v >> p;
    while(u!=-1 && v!=-1 && p!=-1){
        cria_arestra(lista,u,v,p,orientado);
        cin >> u >> v >> p;
    }

    //Mostrar o grafo criado 
    for (i=0;i<nVertices;i++){
        for(it=lista[i].begin();it!=lista[i].end();it++)
            cout << i << " " << it->v << " " << it->peso << endl;
    }

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(lista[i].size()!=0)
            lista[i].pop_front();
    }

    return 0;
}