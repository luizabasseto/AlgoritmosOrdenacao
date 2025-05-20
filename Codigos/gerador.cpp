#include <iostream>
#include <vector>
#include <random>

std::vector<int> GerarNumeros(int n) {
    std::vector<int> lista;
    lista.reserve(n);

    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000);

    for (int i = 0; i < n; i++) {
        lista.push_back(dis(gen));
    }

    return lista;
}
