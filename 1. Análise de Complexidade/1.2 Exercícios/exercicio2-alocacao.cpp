#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void MaxMin(int *v, int n, int *max, int *min, int *c)
{
    int i;
    *max = *min = v[0];
    for (i = 1; i < n; i++)
    {
        *c = *c + 1;
        if (v[i] > *max)
            *max = v[i];
        *c = *c + 1;
        if (v[i] < *min)
            *min = v[i];
    }
}

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    srand(time(NULL));

    int n;
    cout << "Tamanho do vetor: ";
    cin >> n;

    int *v = new int[n];
    int max, min, c = 0;

    cout << "Vetor original: ";
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
        // cout << v[i] << " ";
    }

    // Tempo inicial
    clock_t t = clock();
    MaxMin(v, n, &max, &min, &c);
    // Tempo final
    t = clock() - t;

    cout << "\nMaior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << c << endl;
    cout << "\nTempo de execução: " << ((float)t) / CLOCKS_PER_SEC << "s" << endl;
    delete[] v;
    return 0;
}
