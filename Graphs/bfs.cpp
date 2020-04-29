#include<iostream>
#include<list>

using namespace std;

//Estrutura para armazenar as arestas
struct no
{
    int v; //vertice adjacente
    int peso; //peso da aresta
};

//Percurso em largura
void bfs(list<no>adj[], int nVertices, int s)
{
    list<int> q; // fila auxiliar
    int state[100]; // -1: não descoberto, 0: descoberto, 1: processado 
    int p[100]; // pai (-1 se não tiver pai)
    int i; // contador
    int u,v; // var aux para indicar origem e destino de uma aresta
    list<no>::iterator it; // iterador para varrer a lista
    
    // Inicialização
    for(i=0;i<nVertices;i++)
    {
        state[i] = -1;
        p[i] = -1;
    }
    state[s] = 0; // descoberto
    p[s] = -1; // vértice s é o pai de todos, então não tem pai
    q.push_back(s);
    
    // Percurso em largura
    while(q.size()!=0)
    {
        u = q.front();
        q.pop_front();
        cout << u << endl;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            v = it->v;
            cout << u << " " << v << endl;
            if (state[v] == -1)
            {
                state[v] = 0;
                p[v] = u;
                q.push_back(v);
            }
        }
        state[u] = 1;
    }
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
   
    //Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v >> p;
    s = u;
    while(u!=-1 && v!=-1){
        cria_arestra(lista,u,v,p,orientado);
        cin >> u >> v >> p;
    }

    //Busca em largura
    bfs(lista,nVertices,s);

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(lista[i].size()!=0)
            lista[i].pop_front();
    }

    return 0;
}
