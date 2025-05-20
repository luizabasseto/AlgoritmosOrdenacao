#include <iostream>
#include <vector>

int buscaBinaria(int elemento)
{

    return -1;
}

int buscaLinear(int elemento, int *lista, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (lista[i] == elemento)
        {
            return i;
        }
    }
    return -1;
};