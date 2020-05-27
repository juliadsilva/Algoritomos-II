#include<iostream>
#include<list>
#include<climits>

using namespace std;

//Estrutura para armazenar as arestas
struct no
{
    int v; //vertice adjacente
};

void ordenacao_topologica(int *f, int nVertices){

    int i,j;
    int temp;
    int saida[10];

    for (i=0;i<nVertices; i++){
        saida [i] = f[i];
    }
   
    for (i = 1; i < nVertices; i++) {
        for (j = 0; j < i; j++) {
            if (f[i] > f[j]) {
                temp = f[i];
                f[i] = f[j];
                f[j] = temp;
            }
        }
    }

    for (i=0; i < nVertices; i++)
        for (j = 0; j < nVertices; j++)
            if(f[i] == saida[j])
               cout << j << " ";

    cout << endl;

}


void dfsVisit (list<no> adj[], int &u, int *color, int &time, int *d, int *pi, int *f){

    list<no>::iterator p;
    int auxiliar;
    
    color[u] = 1;
    time = time + 1;
    d[u]=time;

    for(p = adj[u].begin(); p != adj[u].end(); p++){
        auxiliar = p -> v;
        if(color[auxiliar] == 0){
            pi[auxiliar] = u;
            dfsVisit(adj,auxiliar, color, time, d, pi, f);
        }
    }

    color[u] = 2;
    time = time + 1;
    f[u] = time;
}

void dfs (list<no> adj[], int nVertices){
    
    int u; 
    int color[10]; //0 - white / 1 - grey / 2 - black
    int time;
    int pi[10];
    int d[10];
    int f[10];

    for(u = 0; u < nVertices; u++){
        color[u] = 0;
        pi[u] = NULL;
    }

    time = 0 ;
    
    for(u = 0; u < nVertices; u++){
        if (color[u] == 0) 
            dfsVisit(adj, u, color, time, d, pi, f);
    }

    ordenacao_topologica(f,nVertices);
    
}

//Cria aresta do vertice u ao vertice v, com peso p
void cria_arestra(list<no>grafo[], int u, int v, int orientado)
{
    no aux; //vriavel auxiliar para inserir o nó no grafo

    aux.v = v;
    grafo[u].push_back(aux);
    if(orientado==0)
    {
        aux.v = u;
        grafo[v].push_back(aux);
    }
}

int main()
{
    list<no> grafo[10]; //lista de adjacencias
    list<no>::iterator it; ///iterador para varrer a lista
    int u,v; //vertices de origem e destino, respesctivamente
    int orientado; //um se for orientado, zero caso contrario    
    int nVertices; //numero de vertices do grafo
    int i;
    
    //Lendo o numero de vertices do grafo
    cin >> nVertices;

    //Verificando se o grafo é orientado ou nao
    orientado = 1;
  
    ///Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v;
    while(u!=-1 && v!=-1){
        cria_arestra(grafo,u,v,orientado);
        cin >> u >> v;
    }

    //Cálculo do Caminho de Custo Mínimo
    dfs(grafo,nVertices);

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(grafo[i].size()!=0)
            grafo[i].pop_front();
    }

    return 0;
}