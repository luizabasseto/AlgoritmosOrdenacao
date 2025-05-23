#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include "timeMeasure.hpp"

using namespace std;

void timeMean(void (*sortFunc)(vector<int>&, int), vector<int> vet, int n, const string& nome) {
    cout << "Reorganização com " << nome << endl;
    auto inicio = chrono::high_resolution_clock::now();
    sortFunc(vet, n);
    auto fim = chrono::high_resolution_clock::now();
    double dur = chrono::duration_cast<chrono::duration<double>>(fim - inicio).count();
    cout << "Tempo Gasto: " << dur << " segundos" << endl << endl;
}

void timeSearch(int (*searchFunc)(int, std::vector<int>&, int), int elem, std::vector<int> vet, int n, const std::string& nome) {
    using namespace std::chrono;
    std::cout << nome << std::endl;
    auto inicio = high_resolution_clock::now();
    int resultado = searchFunc(elem, vet, n);
    auto fim = high_resolution_clock::now();
    double dur = duration_cast<duration<double>>(fim - inicio).count();
    std::cout << "Resultado: " << resultado << " | Tempo Gasto: " << dur << " segundos\n" << std::endl;
}
