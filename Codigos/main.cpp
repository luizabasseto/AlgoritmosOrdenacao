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
    int n1 = 12000, n2 = 70000, n3 = 100000;

    /*createArchiveBin("ArquivoN1_", n1);
    createArchiveBin("ArquivoN2_", n2);
    createArchiveBin("ArquivoN3_", n3);*/

    vector<int> vet1 = ReadArchiveBin("ArquivoN1_", n1);
    vector<int> copy1 = vet1;
    cout << "PARA O TAMANHO 1, de n1=" << n1 << ", com demora de aproximadamente 1s" << endl;
    cout << endl;
    timeMean(BubbleSortOptimized, copy1, n1, "Bubble Sort Otimizado");
    copy1 = vet1;
    timeMean(BubbleSort, copy1, n1, "Bubble Sort Puro");
    copy1 = vet1;
    timeMean(SelectionSortOptimized, copy1, n1, "Selection Sort Otimizado: ");
    copy1 = vet1;
    timeMean(InsertionSort, copy1, n1, "Insertion Sort");
    copy1 = vet1;
    timeSearch(linearSearch, 8, copy1, n1, "Busca Linear em vetor não ordenado");
    timeSearch(binarySearch, 8, copy1, n1, "Busca Binária em vetor não ordenado");
    timeMean(SelectionSort, vet1, n1, "Selection Sort");
    timeSearch(linearSearch, 8, vet1, n1, "Busca Linear em vetor ordenado");
    timeSearch(binarySearch, 8, vet1, n1, "Busca Binária em vetor ordenado");

    cout << "--------------------------------------------\n"<< endl;

    cout << "PARA O TAMANHO 2, de n2=" << n2 << ", com demora de aproximadamente 30s" << endl;
    vector<int> vet2 = ReadArchiveBin("ArquivoN2_", n2);
    vector<int> copy2 = vet2;
    timeMean(SelectionSort, copy2, n2, "Selection Sort");
    copy2 = vet2;
    timeMean(SelectionSortOptimized, copy2, n2, "Selection Sort Otimizado");

    timeSearch(linearSearch, 8, vet2, n2, "Busca Linear em vetor não ordenado");
    timeSearch(binarySearch, 8, vet2, n2, "Busca Binária em vetor não ordenado");
    copy2=vet2;
    timeMean(InsertionSort, copy2, n2, "Insertion Sort");

    timeSearch(linearSearch, 8, copy2, n2, "Busca Linear em vetor ordenado");
    timeSearch(binarySearch, 8, copy2, n2, "Busca Binária em vetor ordenado");
    copy2 = vet2;
    timeMean(BubbleSortOptimized, copy2, n2, "Bubble Sort Otimizado");
    timeMean(BubbleSort, vet2, n2, "Bubble Sort Puro");

    cout << "--------------------------------------------\n"<< endl;

    vector<int> vet3 = ReadArchiveBin("ArquivoN3_", n3);
    vector<int> copy3 = vet3;
    cout << "PARA O TAMANHO 3, de n3=" << n3 << ", com demora de aproximadamente 3min" << endl;
    timeMean(SelectionSort, copy3, n3, "Selection Sort");
    copy3 = vet3;
    timeMean(InsertionSort, copy3, n3, "Insertion Sort");
    copy3 = vet3;
    timeMean(SelectionSortOptimized, copy3, n3, "Selection Sort Otimizado");
    copy3 = vet3;
    timeMean(BubbleSortOptimized, copy3, n3, "Bubble Sort Otimizado");
    timeMean(BubbleSort, vet3, n3, "Bubble Sort Puro");

    // Armazenar vetores ordenados em arquivos binários
    createArchiveBinOrdenado(vet1, "ArquivoN1_Ordenado_", n1);
    createArchiveBinOrdenado(vet2, "ArquivoN2_Ordenado_", n2);
    createArchiveBinOrdenado(vet3, "ArquivoN3_Ordenado_", n3);

    return 0;
}