#include <iostream>
#include <vector>

template<typename T>

bool BubbleSortOtimizado(vector<T>& lista , int n){
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

    return verificarOrdenacao(lista,n);
}

bool BubbleSortPuro(vector<T>& lista, int n){

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

bool verificarOrdenacao(vector<T>& lista, int n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        if (lista[i] > lista[i + 1])
        {
            return false;
        }
    }
    return true;
};