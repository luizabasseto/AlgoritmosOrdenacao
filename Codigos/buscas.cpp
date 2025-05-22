#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int buscaBinaria(int elem, vector<T> &vet, int n)
{
    T low = vet[0];
    T high = vet[n-1];
    while (low <= high)
    {
        T mid = low + (high - low) / 2;

        if (elem == vet[mid])
            return mid;

        if (elem > vet[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

template <typename T>
int buscaLinear(int elemento, vector<T> &vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == elemento)
        {
            return i;
        }
    }
    return -1;
};