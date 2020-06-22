#include<iostream>
#include<list>
#include<climits>
#include<string.h>

using namespace std;

//Estrutura para armazenar as arestas
struct no
{
    int v; //vertice adjacente
    int peso; //peso da aresta
};


/*
Codigo e cidades da Alemanha
0 - Frankfurt
1 - Mannheim
2 - Wurzburg
3 - Stuttgart
4 - Karlsruhe
5 - Erfut
6 - Nurnberg
7 - Kassel
8 - Augsburg
9 - Munchen
*/

//Cidade para codigo
int codigo(char cidade[1000]){

    if (strcmp(cidade,"Frankfurt") == 0)
        return 0;
    else if (strcmp(cidade,"Mannheim") == 0)
        return 1;
     else if (strcmp(cidade,"Wurzburg") == 0)
        return 2;
    else if (strcmp(cidade,"Stuttgart") == 0)
        return 3;
    else if (strcmp(cidade,"Karlsruhe") == 0)
        return 4;
    else if (strcmp(cidade,"Erfut") == 0)
        return 5;
    else if (strcmp(cidade,"Nurnberg") == 0)
        return 6;
    else if (strcmp(cidade,"Kassel") == 0)
        return 7;
    else if (strcmp(cidade,"Augsburg") == 0)
        return 8;
    else if (strcmp(cidade,"Munchen") == 0)
        return 9;
    
}

//Codigo para cidade
int cidade(int codigo){

    switch (codigo)
    {
    case 0:
        cout <<"Frankfurt";
        break;
    case 1:
        cout<<"Mannheim";
        break;
    case 2:
        cout<<"Wurzburg";
        break;
    case 3:
        cout<<"Stuttgart";
        break;
    case 4:
        cout<<"Karlsruhe";
        break;
    case 5:
        cout<<"Erfut";
        break;
    case 6:
        cout<<"Nurnberg";
        break;
    case 7:
        cout<<"Kassel";
        break;
    case 8:
        cout<<"Augsburg";
        break;
    case 9:
        cout<<"Munchen";
        break;
    
    }

    return 0;
}

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
        caminho[0] = end;
        aux = end;
        i = 1;
        while(parent[aux] != start){
            caminho[i] = parent[aux];
            aux = parent [aux];
            i++;
        }
        caminho[i] = start;

        cout<<"Caminho: ";     
        while(i > 0){
            aux = caminho[i];
            cidade(aux);
            cout << " - ";
            i--;
        }
        aux = caminho[i];
        cidade(aux);
        cout << endl;
    
        //Mostrado a distancia minimo
        cout << "Distancia: " << distance[end] << " km" << endl;
        
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
    char origem[1000];
    char destino[1000];
    int inicial;
    int final;
    int s;

    //Inicializando variaveis
    orientado = 0;
    nVertices = 10;
    s = 0; //Frankfurt
        
    //Lendo origem e destino
    cin.getline(origem,1000); 
    cin.getline(destino,1000);

    //Linguagem da palavra com o codigo
    inicial = codigo(origem);
    final = codigo(destino);

    ///Lendo informacoes das arestas e inserindo no grafo
    cin >> u >> v >> p;
    while(u!=-1 && v!=-1 && p!=-1){
        cria_arestra(lista,u,v,p,orientado);
        cin >> u >> v >> p;
    }

    //Cálculo do Caminho de Custo Mínimo
    dijkstra(lista,nVertices,inicial,final);

    //Liberar a memoria usada pela lista
    for(i=0;i<nVertices;i++){
        while(lista[i].size()!=0)
            lista[i].pop_front();
    }

    return 0;
}