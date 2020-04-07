#include <iostream>

using namespace std;

void insercaoDireta(int vetor[], int tamanho)
{
    int i,j; // contadores
    int chave;
    for (j=1;j<tamanho;j++)
    {
        chave = vetor[j];
        i = j-1;
        while ((i >= 0) && (vetor[i] > chave))
        {
            vetor[i+1] = vetor[i];
            i = i-1;
        }
        vetor[i+1] = chave;
    }
}

int binaria(int vetor[], int tamanho, int x)
{
    bool achou; // var aux p/ busca
	int baixo, meio, alto; // var aux
	baixo = 0;
	alto = tamanho - 1;
	achou = false;
	while ((baixo <= alto) && (achou == false))
	{
		meio = (baixo + alto) / 2;
		if (x < vetor[meio])
			alto = meio - 1;
		else if (x > vetor[meio])
			baixo = meio + 1;
		else
			achou = true;
	}

	if (achou)
		return meio;
	else
		return -1;
}


int main(){

    int IDS[20]; //vetor lista de IDS 
    int X; //auxiliar   
    int ID; //id a ser procurado
    int acesso; //posicao x do vetor
    int i,j; //contador

    //Lendo lista
    i=0;
    cin >> X;
    while (X != -1){
        IDS[i] = X;
        i++;
        cin >> X;
    }

    //Ordenando vetor
    insercaoDireta(IDS,i);

    //Lendo ID a ser procurado
    cin >> ID;

    //Procurando ID
	acesso = binaria (IDS, i, ID);

	// Mostrando resultadoP
	if (acesso == -1)
	    cout << "Nao possui acesso" << endl;
	else{
		cout << "Possui acesso" << endl;
    }

	return 0;
}
