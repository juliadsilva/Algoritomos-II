#include <iostream>

using namespace std;

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

int main()
{

	int i; //contador
	int x; //elemento a ser procurando
	int T; //numero de elementos do vetor
	int V[100]; //vetor
	int pos; //posicao x do vetor

	// Lendo numero de elementos do vetor
	cout << "Tamanho do vetor: " << endl;
	cin >> T;

	// Lendo Vetor
	for(i = 0; i < T; i++)
		cin >> V[i];

	// Lendo elemento a ser procurado
	cout << "Qual e o numero a ser procurado?" << endl;
	cin >> x;

	// Procutando elemento no vetor
	pos = binaria (V, T, x);

	// Mostrando resultado
	if (pos == -1)
		cout << "Nao esta no vetor" << endl;
	else
	{
		cout << "Esta na posicao: " << endl;
		cout << pos << endl;
	}

	return 0;
}
