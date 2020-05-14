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

void dijkstra(list<no>adj[], int nVertices, int start, int end)
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
    int caminho[10];
    int aux;
    int i,j; //contadores

    custo = 0;

    for(u=0;u<nVertices;u++){
        intree[u] = false;
        distance[u] = INT_MAX;
        parent[u] = -1;
    } 
    
    distance[start] = 0;
    v = start; 
    
    while(intree[v] == false){
        intree[v] = true;
        for(p = adj[v].begin(); p != adj[v].end(); p++){
            destino = p->v;
            weight = p->peso;
            if(distance[destino] > (distance[v] + weight)){
               distance[destino] = distance[v] + weight;
               parent[destino] = v;
            }
        }

        v = 1;
        dist = INT_MAX;
        
        for(u=1;u<(nVertices);u++){
            if(intree[u]==false && dist>distance[u]){
                dist = distance[u];
                v = u;
            }  
        }              
    } 
        //Mostrando o caminho
        cout << "Menor caminho: ";
        caminho[0] = end;
        aux = end;
        i = 1;
        while(parent[aux] != start){
            caminho[i] = parent[aux];
            aux = parent [aux];
            i++;
        }
        caminho[i] = start;
                
        while(i >= 0){
            cout << caminho[i] << " ";
            i--;
        }
        cout << endl;
    
        //Mostrado o custo minimo
        cout << "Custo: " << distance[end] << endl;
        
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
    int e; //vertice final 
    
    //Lendo o numero de vertices do grafo
    cin >> nVertices;

    //Verificando se o grafo é orientado ou nao
    cin >> orientado;

    //Lendo vértice inicial do caminho
    cin >> s;

    //Lendo vertice de destio
    cin >> e;
   
    ///Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v >> p;
    while(u!=-1 && v!=-1 && p!=-1){
        cria_arestra(lista,u,v,p,orientado);
        cin >> u >> v >> p;
    }

    //Cálculo do Caminho de Custo Mínimo
    dijkstra(lista,nVertices,s,e);

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(lista[i].size()!=0)
            lista[i].pop_front();
    }

    return 0;
}