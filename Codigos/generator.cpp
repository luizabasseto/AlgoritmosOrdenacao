#include <iostream>
#include <vector>
#include <random>

std::vector<int> randGenerator(int n) {
    std::vector<int> vet;
    vet.reserve(n);

    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000);

    for (int i = 0; i < n; i++) {
        vet.push_back(dis(gen));
    }

    return vet;
}
