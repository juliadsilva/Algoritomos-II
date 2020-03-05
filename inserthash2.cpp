#include<iostream>

using namespace std;

struct dado
{
    int k;
    int status;
};

// Funcao auxiliar 1 para inserir a chave key em uma tabela hash de tamanho m
int h1(int k, int m)
{
    int h1 = k % m; // posicao a inserir
    
    if(h1 < 0)
        h1 = h1 + m;
        
    return h1;    
}

// Funcao auxiliar 2 para inserir a chave key em uma tabela hash de tamanho m
int h2(int k, int m)
{
    int h2 = 1+ (k % (m-1)); // posicao a inserir
    
    if(h2 < 0)
        h2 = h2+m;
        
    return h2;    
}


// Funcao que implementa a sondagem double hashing
int hashp(int k, int i, int m)
{
    int pos = (h1(k,m) + i*h2(k,m)) % m;
    
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
    int k; // chave
    int i; // contador
    dado tabela[100]; // tabela hash
    
    // Lendo o tamanho da tabela
    cin >> m;
    
    // Inicializando a tabela
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