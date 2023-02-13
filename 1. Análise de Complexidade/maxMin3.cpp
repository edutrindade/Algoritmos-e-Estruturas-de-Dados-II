#include <iostream>
#include <windows.h>

using namespace std;

void MaxMin3(int Vet[], int n, int &max, int &min, int &comparacoes)
{
    int i, FimDoAnel;
    // Verifica se o tamanho é par ou ímpar
    if ((n % 2) > 0)
    {
        Vet[n] = Vet[n - 1];
        FimDoAnel = n;
    }
    else
    {
        FimDoAnel = n - 1;
    }
    // Define os primeiros min e max
    comparacoes++;
    if (Vet[0] > Vet[1])
    {
        max = Vet[0];
        min = Vet[1];
    }
    else
    {
        max = Vet[1];
        min = Vet[0];
    }
    // Comparação aos pares
    for (i = 2; i < FimDoAnel; i += 2)
    {
        comparacoes++;
        if (Vet[i] > Vet[i + 1])
        {
            // Se o elemento i-1 é maior que i, ele pode ser o maior de todos
            comparacoes++;
            if (Vet[i] > max)
            {
                max = Vet[i];
            }
            // Senão, o elemento i pode ser o menor de todos
            comparacoes++;
            if (Vet[i + 1] < min)
            {
                min = Vet[i + 1];
            }
        }
        else
        {
            // Se o elemento i-1 é menor que i, ele pode ser o menor de todos
            comparacoes++;
            if (Vet[i] < min)
            {
                min = Vet[i];
            }
            // Senão, o elemento i pode ser o maior de todos
            comparacoes++;
            if (Vet[i + 1] > max)
            {
                max = Vet[i + 1];
            }
        }
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int VetMelhorCaso[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int VetPiorCaso[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int VetCasoMedio[] = {9, 7, 5, 10, 4, 1, 8, 2, 3, 1};

    int max, min, comparacoes = 0;

    MaxMin3(VetMelhorCaso, 10, max, min, comparacoes); // Chamada da função
    cout << "\nMelhor caso (1.5n - 2)" << endl;
    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = 3n/2 – 3 + 1 = 3n/2 - 2 = 1.5n - 2

    comparacoes = 0;

    MaxMin3(VetPiorCaso, 10, max, min, comparacoes); // Chamada da função
    cout << "\nPior caso (1.5n - 2) " << endl;
    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = 3n/2 – 3 + 1 = 3n/2 - 2 = 1.5n - 2

    comparacoes = 0;

    MaxMin3(VetCasoMedio, 10, max, min, comparacoes); // Chamada da função
    cout << "\nCaso médio (1.5n - 2)" << endl;
    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = 3n/2 – 3 + 1 = 3n/2 - 2 = 1.5n - 2

    return 0;
}