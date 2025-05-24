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
    int n1 = 15000, n2 = 100000, n3 = 200000;

    /*createArchiveBin("ArquivoN1_", n1);
    createArchiveBin("ArquivoN2_", n2);
    createArchiveBin("ArquivoN3_", n3);*/

    vector<int> vet1 = ReadArchiveBin("ArquivoN1_", n1);
    vector<int> copy1 = vet1;
    cout << "PARA O TAMANHO 1, com demora de aproximadamente 1s" << endl;
    cout << endl;
    timeMean(BubbleSortOptimized, copy1, n1, "Bubble Sort Otimizado");
    copy1 = vet1;
    timeMean(BubbleSort, copy1, n1, "Bubble Sort Puro");
    copy1 = vet1;
    timeMean(SelectionSort, copy1, n1, "Selection Sort");
    copy1 = vet1;
    timeMean(InsertionSort, copy1, n1, "Insertion Sort");
    copy1 = vet1;
    timeMean(InsertionSortOptimized, copy1, n1, "Insertion Sort Otimizado: ");

    cout << "PARA O TAMANHO 2, com demora de aproximadamente 30s" << endl;
    vector<int> vet2 = ReadArchiveBin("ArquivoN2_", n2);
    vector<int> copy2 = vet2;
    timeMean(BubbleSortOptimized, copy2, n2, "Bubble Sort Otimizado");
    copy2 = vet2;
    timeMean(BubbleSort, copy2, n2, "Bubble Sort Puro");
    copy2 = vet2;
    timeMean(SelectionSort, copy2, n2, "Selection Sort");
    copy2 = vet2;
    timeMean(InsertionSort, copy2, n2, "Insertion Sort");
    copy2 = vet2;
    timeSearch(linearSearch, 56, vet2, n2, "Busca Linear em vetor não ordenado");
    timeSearch(binarySearch, 56, vet2, n2, "Busca Binária em vetor não ordenado");

    timeMean(InsertionSortOptimized, vet2, n2, "Insertion Sort Otimizado (para busca)");

    timeSearch(linearSearch, 56, vet2, n2, "Busca Linear em vetor ordenado");
    timeSearch(binarySearch, 56, vet2, n2, "Busca Binária em vetor ordenado");

    vector<int> vet3 = ReadArchiveBin("ArquivoN3_", n3);
    cout << "PARA O TAMANHO 3, com demora de aproximadamente 3min" << endl;
    timeMean(SelectionSort, vet3, n3, "Selection Sort");
    timeMean(InsertionSort, vet3, n3, "Insertion Sort");
    timeMean(InsertionSortOptimized, vet3, n3, "Insertion Sort Otimizado");
    timeMean(BubbleSortOptimized, vet3, n3, "Bubble Sort Otimizado");
    timeMean(BubbleSort, vet3, n3, "Bubble Sort Puro");

    return 0;
}