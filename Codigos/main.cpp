#include <iostream>
#include <vector>
#include <string>

#include "algorithms.hpp"
#include "manipArchives.hpp"
#include "searches.hpp"

using namespace std;

int main()
{
    int n1 = 100;
    /* int n2 = 1000;
    int n3 = 1000000;
    createArchiveBin("ArquivoN1_", n1);
    createArchiveBin("ArquivoN2_", n2);
    createArchiveBin("ArquivoN3_", n3);*/

    vector<int> vet = ReadArchiveBin("ArquivoN1_", n1);

    for (size_t i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;

    BubbleSortOptimized(vet, n1);
    cout << "Após bubble sort" << endl;
    for (size_t i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;

    int index = binarySearch(61, vet, n1);

    cout << index << endl;
}