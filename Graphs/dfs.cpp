#include<iostream>
#include<list>
#include<climits>

using namespace std;

//Estrutura para armazenar as arestas
struct no
{
    int v; //vertice adjacente
};

void dfsvisit(list<no>lista[], int u, int color[], int time, int d[], int pi[], int f[]){
    
    int v; 

    color[u] = 1;
    time = time + 1;
    d[u] = time;

    for(v = lista[u].begin(); v != lista[u].end(); v++){
        if(color(v) == 0){
            pi[v] = u;
            dfsvisit(lista,v,color,time,d,pi,f);
        }
    color[u] = 3;
    f[u] = time;
    time = time + 1;
}
}

void dfs(list<no>adj[], int nVertices){
      
    int color[10]; //0 - white, 1-grey, 2-black
    int pi[10];
    int d[10];
    int f[10];
    int u; 
    int v; 
    int time;

    for(u=0;u<nVertices;u++){
        color[u] = 0;
        pi[u] = NULL;
        time = 0;
    } 

    for(u=0;u<nVertices;u++)
        if(color[u] == 0)
            dfsvisit(adj,u,color,time,d,pi,f);

    
    for(u=0;u<nVertices;u++)
        cout << f[u] << " " << endl;
       
}


//Cria aresta do vertice u ao vertice v, com peso p
void cria_arestra(list<no>lista[], int u, int v, int orientado)
{
    no aux; //vriavel auxiliar para inserir o no na lista

    aux.v = v;
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
    int orientado; //um se for orientado, zero caso contrario    
    int nVertices; //numero de vertices do grafo
    int i;
    
    //Lendo o numero de vertices do grafo
    cin >> nVertices;

    //Verificando se o grafo é orientado ou nao
    cin >> orientado;
  
    ///Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v;
    while(u!=-1 && v!=-1){
        cria_arestra(lista,u,v,orientado);
        cin >> u >> v;
    }

    //Cálculo do Caminho de Custo Mínimo
    dfs(lista,nVertices);

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(lista[i].size()!=0)
            lista[i].pop_front();
    }

    return 0;
}