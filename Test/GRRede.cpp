#include<iostream>
#include<list>
#include<climits>

using namespace std;

//Estrutura para armazenar as arestas
struct no
{
    int v; //vertice adjacente
    int peso; //peso da aresta
};

void prim(list<no>adj[], int nVertices, int s)
{
    bool intree[10];
    int distance[10];
    int parent[10];
    int v; 
    list<no>::iterator p; // iterador para varrer a lista
    int destino;
    int weight;
    int dist;
    int u; 
    int custo;

    custo = 0;

    for(u=0;u<nVertices;u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    } 
    
    distance[s] = 0;
    v = s; 
    
    while(intree[v] == false){
        intree[v] = true;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            destino = p->v;
            weight = p->peso;
            if(distance[destino] > weight && intree[destino]==false){
                distance[destino] = weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;
        
        for(u=0;u<(nVertices);u++){
            if(intree[u]==false && dist>distance[u]){
                dist = distance[u];
                v = u;
            }  
        }
        custo = custo + distance[v];       
    } 

    //Mostrado saida
    cout << "Ligacoes:" << endl;
    for(u=1;u<nVertices;u++)
        cout << parent[u] << " " << u << endl;  
    cout << "Custo total: " << custo << " m" << endl;
}

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
    int s; //vertice inicial
    
    //Lendo o numero de vertices do grafo
    cin >> nVertices;

    //Verificando se o grafo é orientado ou nao
    cin >> orientado;

    //Lendo vértice inicial da árvore
    cin >> s;

    ///Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v >> p;
    while(u!=-1 && v!=-1 && p!=-1){
        cria_arestra(lista,u,v,p,orientado);
        cin >> u >> v >> p;
    }

    //Arvore geradora mínima
    prim(lista,nVertices,s);

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(lista[i].size()!=0)
            lista[i].pop_front();
    }

    return 0;
}