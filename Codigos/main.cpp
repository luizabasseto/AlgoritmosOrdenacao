#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "algorithms.hpp"
#include "manipArchives.hpp"
#include "searches.hpp"
#include "timeMeasure.hpp"

using namespace std;

int main()
{
    int n1 = 15000, n2 = 100000, n3 = 10000000;

    createArchiveBin("ArquivoN1_", n1);
    createArchiveBin("ArquivoN2_", n2);
    createArchiveBin("ArquivoN3_", n3);

    vector<int> vet1 = ReadArchiveBin("ArquivoN1_", n1);
    cout << "PARA O TAMANHO 1, com demora de aproximadamente 1s" << endl;
    cout << endl;
    // timeMean(BubbleSortOptimized, vet1, n1, "Bubble Sort Otimizado");
    timeMean(BubbleSort, vet1, n1, "Bubble Sort Puro");
    timeMean(SelectionSort, vet1, n1, "Selection Sort");
    timeMean(InsertionSort, vet1, n1, "Insertion Sort");
    timeMean(InsertionSortOptimized, vet1, n1, "Insertion Sort Otimizado");

    vector<int> vet2 = ReadArchiveBin("ArquivoN2_", n2);
    cout << "PARA O TAMANHO 2, com demora de aproximadamente 30s" << endl;
    // timeMean(BubbleSortOptimized, vet2, n2, "Bubble Sort Otimizado");
    timeMean(BubbleSort, vet2, n2, "Bubble Sort Puro");
    timeMean(SelectionSort, vet2, n2, "Selection Sort");
    timeMean(InsertionSort, vet2, n2, "Insertion Sort");

    timeSearch(linearSearch, 28, vet2, n2, "Busca Linear em vetor não ordenado");
    timeSearch(binarySearch, 28, vet2, n2, "Busca Binária em vetor não ordenado");

    timeMean(InsertionSortOptimized, vet2, n2, "Insertion Sort Otimizado (para busca)");

    timeSearch(linearSearch, 28, vet2, n2, "Busca Linear em vetor ordenado");
    timeSearch(binarySearch, 28, vet2, n2, "Busca Binária em vetor ordenado");

    // TAMANHO 3
    vector<int> vet3 = ReadArchiveBin("ArquivoN3_", n3);
    cout << "PARA O TAMANHO 3, com demora de aproximadamente 3min" << endl;
    // timeMean(BubbleSortOptimized, vet3, n3, "Bubble Sort Otimizado");
    timeMean(BubbleSort, vet3, n3, "Bubble Sort Puro");
    timeMean(SelectionSort, vet3, n3, "Selection Sort");
    timeMean(InsertionSort, vet3, n3, "Insertion Sort");
    timeMean(InsertionSortOptimized, vet3, n3, "Insertion Sort Otimizado");

    return 0;
}
