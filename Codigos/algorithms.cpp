#include <iostream>
#include <vector>
#include "algorithms.hpp"

using namespace std;

std::vector<long long> BubbleSortOptimized(vector<int> &vet, int n)
{
    bool swapped;
    long long trocas = 0;
    long long comp = 0;

    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                std::swap(vet[j], vet[j + 1]);
                swapped = true;
                trocas++;
            }
            comp++;
        }
        if (!swapped)
        {
            break;
        }
    }
    return {trocas, comp};
}

std::vector<long long> BubbleSort(vector<int> &vet, int n)
{
    long long trocas = 0;
    long long comp = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                std::swap(vet[j], vet[j + 1]);
                trocas++;
            }
            comp++;
        }
    }
    return {trocas, comp};
}

std::vector<long long> InsertionSort(vector<int> &vet, int n)
{
    long long trocas = 0;
    long long comp = 0;
    for (int i = 1; i < n; i++)
    {
        int key = vet[i];
        int j = i - 1;
        while (j >= 0)
        {
            comp++;
            if (key < vet[j])
            {
                vet[j + 1] = vet[j]; 
                trocas++;
                --j;
            }
            else
            {
                break;
            }
        }
        vet[j + 1] = key;
    }
    return {trocas, comp};
}

std::vector<long long> InsertionSortOptimized(vector<int> &vet, int n)
{
    long long trocas = 0;
    long long comp = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            comp++; 
            if (vet[j] < vet[j - 1]) {
                std::swap(vet[j], vet[j - 1]);
                trocas++;
            } else {
                break;
            }
        }
    }
    return {trocas, comp};
}

std::vector<long long> SelectionSort(vector<int> &vet, int n)
{
    
    long long trocas = 0;
    long long comp = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        int index_min = i;
        for (int j = i + 1; j < n; j++)
        {
            comp++; 
            if (vet[j] < vet[index_min])
            {
                index_min = j;
            }
        }
        std::swap(vet[index_min], vet[i]);
        trocas++;
    }
    return {trocas, comp};
}