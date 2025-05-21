#include <iostream>
#include <vector>

using namespace std;

template <typename T>
bool verificarOrdenacao(vector<T> &lista, int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (lista[i] > lista[i + 1])
        {
            return false;
        }
    }
    return true;
}

template <typename T>
bool BubbleSortOtimizado(vector<T> &lista, int n)
{
    bool swapped;

    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                std::swap(lista[j], lista[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    return verificarOrdenacao(lista, n);
}

template <typename T>
bool BubbleSortPuro(vector<T> &lista, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (lista[j] > lista[j + 1])
            {
                std::swap(lista[j], lista[j + 1]);
            }
        }
    }

    return verificarOrdenacao(lista, n);
}

template <typename T>
bool InsertionSort(vector<T> &lista, int n)
{
    int i = 1;
    int chave = lista[i];
    for (int j = 0; j < n; j++)
    {
        chave = lista[i];
        if (chave < lista[j])
        {
            std::swap(chave, lista[j]);
        }
        i++;
    }
}

template <typename T>
bool SelectionSort(vector<T> &lista, int n)
{
    int minElemento = lista[0];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        minElemento = lista[j];
        for (int k = j; k < n; k++)
        {
            if (lista[k] < minElemento)
            {
                std::swap(minElemento, lista[k]);
            }
            j++;
        }
    }
    return verificarOrdenacao(lista, n);
}