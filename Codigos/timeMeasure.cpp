#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <iomanip>
#include "timeMeasure.hpp"

using namespace std;

void timeMean(std::vector<long long> (*func)(std::vector<int> &, int), std::vector<int> &vet, int n, const std::string &nome)
{
    using namespace std::chrono;

    auto inicio = high_resolution_clock::now();
    std::vector<long long> trocas_comp = func(vet, n);
    auto fim = high_resolution_clock::now();

    double dur_sec = duration_cast<duration<double>>(fim - inicio).count();
    std::cout << "Tempo gasto com " << nome << ": " << dur_sec << " segundos" << std::endl;
    std::cout << "Trocas: " << trocas_comp[0] << ", Comparações: " << trocas_comp[1] << std::endl
              << std::endl;
}

void timeSearch(std::vector<long long> (*searchFunc)(int, std::vector<int> &, int),
                int elem, std::vector<int> &vet, int n, const std::string &nome)
{
    using namespace std::chrono;

    const int repeticoes = 100000;
    std::vector<long long> elemento;

    auto inicio = high_resolution_clock::now();
    for (int i = 0; i < repeticoes; ++i)
    {
        elemento = searchFunc(elem, vet, n);
    }
    auto fim = high_resolution_clock::now();

   double dur = duration_cast<duration<double, std::micro>>(fim - inicio).count();
    std::cout << std::fixed << std::setprecision(6);
    double dur_media_ns = static_cast<double>(dur) / repeticoes;

    std::cout << nome << std::endl;
    std::cout << std::fixed << std::setprecision(3)
              << "Resultado Index: " << elemento[0]
              << " | Comparações: " << elemento[1]
              << " | Tempo médio: " << dur_media_ns << " microsegundos\n"
              << std::endl;
}
