#include <iostream>
#include <windows.h>

using namespace std;

void MaxMin2(int Vet[], int n, int &max, int &min, int &comparacoes)
{
    max = Vet[0];
    min = Vet[0];
    for (int i = 1; i < n; i++)
    {
        comparacoes++;
        if (Vet[i] > max)
        {
            max = Vet[i]; // Comparação e atribuição
        }
        else if (Vet[i] < min)
        {
            comparacoes++;
            min = Vet[i]; // Comparação e atribuição
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

    MaxMin2(VetMelhorCaso, 10, max, min, comparacoes); // Chamada da função
    cout << "\nMelhor caso (n - 1)" << endl;
    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = n - 1

    comparacoes = 0;

    MaxMin2(VetPiorCaso, 10, max, min, comparacoes); // Chamada da função
    cout << "\nPior caso (2n - 2) " << endl;
    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = 2(n-1) = 2n - 2

    comparacoes = 0;

    MaxMin2(VetCasoMedio, 10, max, min, comparacoes); // Chamada da função
    cout << "\nCaso médio (3n - 3)" << endl;
    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = ((n-1) + 2(n-1) / 2) = 3n - 3

    return 0;
}