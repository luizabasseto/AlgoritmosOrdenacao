#include <iostream>
#include <vector>

using namespace std;


int binarySearch(int elem, vector<int> &vet, int n)
{
    int low = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (elem == vet[mid])
            return mid;

        if (elem > vet[mid])
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}



int linearSearch(int elem, vector<int> &vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vet[i] == elem)
        {
            return i;
        }
    }
    return -1;

}