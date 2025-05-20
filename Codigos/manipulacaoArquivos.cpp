#include <iostream>
#include <fstream>
#include <vector>
#include <string>		
#include <cstdint>
#include <random>

#include "gerador.cpp"

using namespace std;


void createArquivoBin(string name, int size)
{
    std::string filename = name + std::to_string(size) + ".bin";
    std::vector<int> numeros = GerarNumeros(size);

    std::ofstream arquivo(filename, std::ios::binary);
    if (!arquivo)
    {
        std::cerr << "Erro ao abrir arquivo para escrita.\n";
        return;
    }

    for (int num : numeros)
    {
        // Escreve 4 bytes little endian (inteiro de 32 bits)
        uint32_t val = static_cast<uint32_t>(num);
        arquivo.write(reinterpret_cast<const char *>(&val), sizeof(val));
    }

    arquivo.close();
}

std::vector<int> ReadArquivoBin(string name, int size)
{
    std::string filename = name + std::to_string(size) + ".bin";
    std::vector<int> lista;

    std::ifstream arquivo(filename, std::ios::binary);
    if (!arquivo)
    {
        std::cerr << "Erro ao abrir arquivo para leitura.\n";
        return lista;
    }

    for (int i = 0; i < size; i++)
    {
        uint32_t val;
        arquivo.read(reinterpret_cast<char *>(&val), sizeof(val));
        if (arquivo.gcount() == sizeof(val))
        {
            lista.push_back(static_cast<int>(val));
        }
        else
        {
            break; 
        }
    }

    arquivo.close();
    return lista;
};
