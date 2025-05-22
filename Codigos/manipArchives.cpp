#include <iostream>
#include <fstream>
#include <vector>
#include <string>		
#include <cstdint>
#include <random>

#include "generator.hpp"

using namespace std;


void createArchiveBin(string name, int n)
{
    std::string filename = name + std::to_string(n) + ".bin";
    std::vector<int> numbers = randGenerator(n);

    std::ofstream archive(filename, std::ios::binary);
    if (!archive)
    {
        std::cerr << "Erro ao abrir archive para escrita.\n";
        return;
    }

    for (int num : numbers)
    {
        uint32_t val = static_cast<uint32_t>(num);
        archive.write(reinterpret_cast<const char *>(&val), sizeof(val));
    }

    archive.close();
}

std::vector<int> ReadArchiveBin(string name, int n)
{
    std::string filename = name + std::to_string(n) + ".bin";
    std::vector<int> vet;

    std::ifstream archive(filename, std::ios::binary);
    if (!archive)
    {
        std::cerr << "Erro ao abrir archive para leitura.\n";
        return vet;
    }

    for (int i = 0; i < n; i++)
    {
        uint32_t val;
        archive.read(reinterpret_cast<char *>(&val), sizeof(val));
        if (archive.gcount() == sizeof(val))
        {
            vet.push_back(static_cast<int>(val));
        }
        else
        {
            break; 
        }
    }

    archive.close();
    return vet;
};
