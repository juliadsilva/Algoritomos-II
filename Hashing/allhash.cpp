#include<iostream>

using namespace std;

struct dado
{
    int k;
    int status; // 0-vazio, 1-ocupado, 2-removido
};

// Funcao auxiliar um para inserir a chave key em uma tabela hash de tamanho m
int h1(int k, int m)
{
    int h1 = k % m; // posicao a inserir
    
    if(h1 < 0)
        h1 = h1 + m;
        
    return h1;    
}

// Funcao auxiliar dois para inserir a chave key em uma tabela hash de tamanho m
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

// Pesquisando a chave na tabela t
int hash_scarch(dado t[], int m, int k)
{
    int i,j; // contadores
    
    i = 0;
    do
    {
        j = hashp(k,i,m);
        if(t[j].k == k)
        {
            return j;
        }
        i++;
    
    }while (t[j].status!= 0 && i!=m);
    
    return -1;
}

// Remove a chave k da tabela t
// Retorna 0 se a chave for removida, -1 caso contrario
int hash_remove(dado t[], int m, int k){

    int pos; //posicao k na tabela t

    pos = hash_scarch(t,m,k);

    if (pos != -1){

        t[pos].k = -1;
        t[pos].status = 2;
        return 0;
    }

    else return -1;

}

int main()
{
    int m; // tamanho da tabela
    int k; // chave
    int i; // contador
    int pos; // posição da chave na tabela
    int remove; // retorno da função de remoção
    dado tabela[100]; // tabela hash

    int OP; // opção do menu 1: inserir 2: pesquisar 3: remover 4: listar 5: sair do programa
    
    // Lendo o tamanho da tabela
    cin >> m;
    
    // Inicializando a tabela
    for(i=0;i<m;i++)
    {
        tabela[i].status = 0;
        tabela[i].k = -1;
    }
    
    cin >> OP;

    while (OP != 5)
    {
        switch (OP)
        {
        case 1:
            cin >> k;
            hash_insert(tabela,m,k);
            break;
        
        case 2:
            cin >> k;
            pos = hash_scarch (tabela,m,k); 
            cout << pos << endl;
            break;

        case 3:
            cin >> k;
            remove = hash_remove(tabela,m,k);
            break;

        case 4:
            for(i=0;i<m;i++)
                cout << tabela[i].k << " ";
            cout << endl;   
            break;
        }
        
        cin >> OP;

    }
    
    return 0;

}