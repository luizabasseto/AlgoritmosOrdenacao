#include <iostream>
#include <vector>
#include "algorithms.hpp"

using namespace std;


void BubbleSortOptimized(vector<int> &vet, int n)
{
    bool swapped;

    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                std::swap(vet[j], vet[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}


void BubbleSort(vector<int> &vet, int n)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                std::swap(vet[j], vet[j + 1]);
            }
        }
    }


}



void InsertionSort(vector<int> &vet, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = vet[i];
        int j = i - 1;

        while (j >= 0 && key < vet[j])
        {
            vet[j + 1] = vet[j];
            --j;
        }
        vet[j + 1] = key;
    }
}


void InsertionSortOptimized(vector<int> &vet, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && vet[j] < vet[j - 1]; j--)
        {
            swap(vet[j], vet[j - 1]);
        }
    }
}


void SelectionSort(vector<int> &vet, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int index_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[j] < vet[index_min])
                index_min = j;
        }
        std::swap(vet[index_min], vet[i]);
    }
}