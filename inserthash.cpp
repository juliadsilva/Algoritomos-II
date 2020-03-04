#include<iostream>
#include<iomanip>

using namespace std;

struct dado
{
    int k;
    int status;
};

// Funcao auxiliar para inserir a chave key em uma tabela hash de tamanho m
int h1(int key, int m)
{
    int pos = key % m; // posicao a inserir
    
    // Se a posicao for negativa, temos que somar m
    if(pos < 0)
        pos += m;
        
    return pos;    
}

// Funcao auxiliar para inserir a chave key em uma tabela hash de tamanho m
int h2(int key, int m)
{
    int pos = 1+ (key % (m-1)); // posicao a inserir
    
    // Se a posicao for negativa, temos que somar m
    if(pos < 0)
        pos += m;
        
    return pos;    
}


// Funcao que implementa a sondagem double hashing
int hashp(int k, int i, int m)
{
    int pos = (h1(k,m) + i*h2(k,m)) % m;
    
    // Se a posicao for negativa, temos que somar m
    if(pos < 0)
        pos += m;
        
    return pos;
}

// Insere a chave k na tabela t
int hash_insert(dado t[], int m, int k)
{
    int i,j; // contadores
    
    i = 0;
    do
    {
        j = hashp(k,i,m);
        if(t[j].status != 1)
        {
            t[j].k = k;
            t[j].status = 1;
            return j;
        }
        else
            i++;
    
    }while(i != m);
    
    return -1;
}

int main()
{
    int m; // tamanho da tabela
    int k; // chave a ser armazenada
    int i; // contador
    dado tabela[100]; // tabela hash
    
    // Lendo o tamanho da tabela
    cin >> m;
    
    // Inicializando a tabela (tabela vazia)
    for(i=0;i<m;i++)
    {
        tabela[i].status = 0;
        tabela[i].k = -1;
    }
    
    // Lendo dados e inserindo na tabela
    cin >> k;
    while (k != 0)
    {
        hash_insert(tabela,m,k);
        cin >> k;
    }
    
    // Mostrando a tabela
    for(i=0;i<m;i++)
        cout << tabela[i].k << " ";
    cout << endl;    
    
    return 0;
}