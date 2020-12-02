#include <cstddef>
#include <iostream>

using namespace std;

struct aluno
{
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    double media;

};

int main()
{
    aluno *dados = NULL;
    dados = new aluno();
    
    double soma;
 
    cin >> dados->nota1;
    cin >> dados->nota2;
    cin >> dados->nota3;
    cin >> dados->nota4;
    
    soma = dados->nota1 + dados->nota2 + dados->nota3 + dados->nota4;

    dados->media = soma / 4;
    cout << fixed;
    cout.precision(2);
    cout << dados->media << endl;

    delete dados;

    return 0;
}
