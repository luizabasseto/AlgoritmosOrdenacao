#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "algorithms.hpp"
#include "manipArchives.hpp"
#include "searches.hpp"

using namespace std;

int main()
{
    int n1 = 10000;
    int n2 = 10000;
    int n3 = 35000;
    createArchiveBin("ArquivoN1_", n1);
    createArchiveBin("ArquivoN2_", n2);
    createArchiveBin("ArquivoN3_", n3);

    vector<int> vet = ReadArchiveBin("ArquivoN1_", n1);

    cout << "PARA O TAMANHO 1, com demora de aproximadamente 1s" << endl;

    cout << "Reorganização com Bubble Sort Otimizado" << endl;
    auto inicio = std::chrono::high_resolution_clock::now();
    vector<int> trocas_comp = BubbleSortOptimized(vet, n1);
    auto fim = std::chrono::high_resolution_clock::now();
    double dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;
    cout << "A função teve um total de " << trocas_comp[0] << " trocas e " << trocas_comp[1] << " comparações" << endl;
    cout << endl;

    cout << "Reorganização com Bubble Sort Puro" << endl;
    vet = ReadArchiveBin("ArquivoN1_", n1);
    inicio = std::chrono::high_resolution_clock::now();
    BubbleSort(vet, n1);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Selection Sort" << endl;
    vet = ReadArchiveBin("ArquivoN1_", n1);
    inicio = std::chrono::high_resolution_clock::now();
    SelectionSort(vet, n1);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Insertion Sort" << endl;
    vet = ReadArchiveBin("ArquivoN1_", n1);
    inicio = std::chrono::high_resolution_clock::now();
    InsertionSort(vet, n1);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Insertion Sort Otimizado" << endl;
    vet = ReadArchiveBin("ArquivoN1_", n1);
    inicio = std::chrono::high_resolution_clock::now();
    InsertionSortOptimized(vet, n1);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    vector<int> vet2 = ReadArchiveBin("ArquivoN2_", n2);
    cout << "PARA O TAMANHO 2, com demora de aproximadamente 30s" << endl;

    cout << "Reorganização com Bubble Sort Otimizado" << endl;
    auto inicio = std::chrono::high_resolution_clock::now();
    trocas_comp = BubbleSortOptimized(vet2, n2);
    auto fim = std::chrono::high_resolution_clock::now();
    double dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Bubble Sort Puro" << endl;
    vet2 = ReadArchiveBin("ArquivoN1_", n2);
    inicio = std::chrono::high_resolution_clock::now();
    BubbleSort(vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Selection Sort" << endl;
    vet2 = ReadArchiveBin("ArquivoN1_", n2);
    inicio = std::chrono::high_resolution_clock::now();
    SelectionSort(vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Insertion Sort" << endl;
    vet2 = ReadArchiveBin("ArquivoN1_", n2);
    inicio = std::chrono::high_resolution_clock::now();
    InsertionSort(vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    vet2 = ReadArchiveBin("ArquivoN2_", n2);
    cout << "Busca Binária para o valor 28 utilizando do vet2or não ordenado";
    inicio = std::chrono::high_resolution_clock::now();
    linearSearch(28, vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;

    cout << "Busca Linear para o valor 28 utilizando do vet2or não ordenado";
    inicio = std::chrono::high_resolution_clock::now();
    linearSearch(28, vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;

    cout << "Reorganização com Insertion Sort Otimizado" << endl;

    inicio = std::chrono::high_resolution_clock::now();
    InsertionSortOptimized(vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Busca Binária para o valor 28 utilizando do Vetor já ordenado";
    inicio = std::chrono::high_resolution_clock::now();
    linearSearch(28, vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;

    cout << "Busca Linear para o valor 28 utilizando do Vetor já ordenado";
    inicio = std::chrono::high_resolution_clock::now();
    linearSearch(28, vet2, n2);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;

    vector<int> vet3 = ReadArchiveBin("ArquivoN3_", n3);
    cout << "PARA O TAMANHO 3, com demora de aproximadamente 3min" << endl;

    cout << "Reorganização com Bubble Sort Otimizado" << endl;
    auto inicio = std::chrono::high_resolution_clock::now();
    trocas_comp =  BubbleSortOptimized(vet3, n3);
    auto fim = std::chrono::high_resolution_clock::now();
    double dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Bubble Sort Puro" << endl;
    vet3 = ReadArchiveBin("ArquivoN1_", n3);
    inicio = std::chrono::high_resolution_clock::now();
    BubbleSort(vet3, n3);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Selection Sort" << endl;
    vet3 = ReadArchiveBin("ArquivoN1_", n3);
    inicio = std::chrono::high_resolution_clock::now();
    SelectionSort(vet3, n3);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Insertion Sort" << endl;
    vet3 = ReadArchiveBin("ArquivoN1_", n3);
    inicio = std::chrono::high_resolution_clock::now();
    InsertionSort(vet3, n3);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;

    cout << "Reorganização com Insertion Sort Otimizado" << endl;
    vet3 = ReadArchiveBin("ArquivoN1_", n3);
    inicio = std::chrono::high_resolution_clock::now();
    InsertionSortOptimized(vet3, n3);
    fim = std::chrono::high_resolution_clock::now();
    dur_sec = std::chrono::duration_cast<std::chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur_sec << " segundos" << endl;
    cout << endl;
}