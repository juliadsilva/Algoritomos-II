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

    int N; //numero de alunos
    int ALUNOS[1000]; //vetor das matriculas 
    int MATRI; //matricula a ser procurada
    int corredor; //posicao x do vetor
    int i; //contador

    cin >> N;
    
    //Lendo vetor 
    for (i=0;i<N;i++)
        cin >> ALUNOS[i];    

    //Ordenando vetor
    insercaoDireta(ALUNOS,N);

    //Lendo ID a ser procurado
    cin >> MATRI;

    //Procurando ID
	corredor = binaria (ALUNOS, N, MATRI);

	// Mostrando resultadoP
	if (corredor == -1)
	    cout << "Nao localizado" << endl;
	else{
		cout << "Corredor " << corredor << endl;
    }

	return 0;
}
