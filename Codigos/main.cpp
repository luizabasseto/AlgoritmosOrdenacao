#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>
#include "algorithms.hpp"

using namespace std;
using namespace chrono;

void loadFromFile(const string& filename, vector<int>& vet) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Erro ao abrir o arquivo " << filename << endl;
        exit(1);
    }

    int num;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(int))) {
        vet.push_back(num);
    }
    file.close();
}

void saveToFile(const string& filename, const vector<int>& vet) {
    ofstream file(filename, ios::binary);
    for (int val : vet) {
        file.write(reinterpret_cast<const char*>(&val), sizeof(int));
    }
    file.close();
}

void runSortTest(const string& name, vector<int> vet, vector<int> (*sortFunc)(vector<int>&, int)) {
    int n = vet.size();
    auto start = high_resolution_clock::now();
    vector<int> result = sortFunc(vet, n);
    auto end = high_resolution_clock::now();

    double duration = duration_cast<milliseconds>(end - start).count() / 1000.0;
    cout << fixed << setprecision(3);
    cout << "Tempo com " << name << ": " << duration << " segundos" << endl;
    cout << "Trocas: " << result[0] << ", Comparações: " << result[1] << endl;

    // Salva vetor ordenado para testes de busca binária
    saveToFile("dados/ordenado_" + name + ".bin", vet);
}

int linearSearch(int target, const vector<int>& vet, int& comps) {
    for (int i = 0; i < vet.size(); ++i) {
        comps++;
        if (vet[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int target, const vector<int>& vet, int& comps) {
    int left = 0, right = vet.size() - 1;
    while (left <= right) {
        comps++;
        int mid = left + (right - left) / 2;
        if (vet[mid] == target)
            return mid;
        else if (vet[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void runSearchTest(const vector<int>& vet, int target, const string& context) {
    int comps = 0;
    auto start = high_resolution_clock::now();
    int pos = linearSearch(target, vet, comps);
    auto end = high_resolution_clock::now();
    double duration = duration_cast<microseconds>(end - start).count() / 1000000.0;

    cout << "\nBusca Linear (" << context << ")\n";
    cout << "Resultado: " << pos << ", Comparações: " << comps << ", Tempo: " << duration << "s" << endl;

    comps = 0;
    start = high_resolution_clock::now();
    pos = binarySearch(target, vet, comps);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start).count() / 1000000.0;

    cout << "Busca Binária (" << context << ")\n";
    cout << "Resultado: " << pos << ", Comparações: " << comps << ", Tempo: " << duration << "s" << endl;
}

int main() {
    vector<int> original;
    loadFromFile("dados/medio.bin", original); // use "pequeno.bin", "medio.bin", ou "grande.bin"

    cout << "Tamanho da entrada: " << original.size() << endl;

    runSortTest("BubbleSort", original, BubbleSort);
    runSortTest("BubbleSortOptimized", original, BubbleSortOptimized);
    runSortTest("InsertionSort", original, InsertionSort);
    runSortTest("InsertionSortOptimized", original, InsertionSortOptimized);
    runSortTest("SelectionSort", original, SelectionSort);

    // Executar buscas
    int target = original.size() > 500 ? original[500] : -1; // Valor garantido
    runSearchTest(original, target, "vetor não ordenado");

    // Carrega vetor já ordenado para testar busca binária corretamente
    vector<int> ordenado;
    loadFromFile("dados/ordenado_InsertionSort.bin", ordenado);
    runSearchTest(ordenado, target, "vetor ordenado");

    return 0;
}
