#include <iostream>
#include <windows.h>

using namespace std;

void MaxMin1(int Vet[], int n, int &max, int &min, int &comparacoes)
{
    max = Vet[0];
    min = Vet[0];
    for (int i = 1; i < n; i++)
    {
        comparacoes++; // Comparação do primeiro if
        if (Vet[i] > max)
        {
            max = Vet[i]; // Atribuição
        }
        comparacoes++; // Comparação do segundo if
        if (Vet[i] < min)
        {
            min = Vet[i]; // Atribuição
        }
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int Vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int max, min, comparacoes = 0;

    MaxMin1(Vet, 10, max, min, comparacoes); // Chamada da função

    cout << "Maior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << comparacoes << endl; // f(n) = 2 (n-1) = 2n - 2
    return 0;
}