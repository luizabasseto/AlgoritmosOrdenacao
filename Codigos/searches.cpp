#include <iostream>
#include <vector>

using namespace std;

std::vector<long long> binarySearch(int elem, vector<int> &vet, int n)
{
    int low = 0;
    int comp = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (elem == vet[mid])
        {
            comp++;
            return {mid,comp};
        }
        if (elem > vet[mid])
        {
            comp++;
            low = mid + 1;
        }
        else
        {
            comp++;
            high = mid - 1;
        }
    }

    return {-1,comp};
}

std::vector<long long> linearSearch(int elem, vector<int> &vet, int n)
{

    int comp =0;
    for (int i = 0; i < n; i++)
    {
        comp++;
        if (vet[i] == elem)
        {
            return {i,comp};
        }
    }
    return {-1,comp};
}

