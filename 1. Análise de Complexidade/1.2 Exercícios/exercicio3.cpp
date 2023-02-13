#include <iostream>
#include <ctime>
#include <chrono>
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

    int v[n], max, min, c = 0;

    cout << "Vetor original: ";
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
        // cout << v[i] << " ";
    }

    auto start = chrono::steady_clock::now();
    MaxMin(v, n, &max, &min, &c);
    auto end = chrono::steady_clock::now();

    cout << "\nMaior: " << max << endl;
    cout << "Menor: " << min << endl;
    cout << "Comparações: " << c << endl;
    cout << "\nTempo de execução: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << endl;
    return 0;
}