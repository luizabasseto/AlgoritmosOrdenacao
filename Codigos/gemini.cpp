/*#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Para std::sort para verificar e para std::is_sorted

#include "algorithms.hpp" // Suas funções de ordenação
#include "searches.hpp"   // Suas funções de busca

// Função auxiliar para imprimir um vetor
void printVector(const std::string &label, const std::vector<int> &vec)
{
    std::cout << label << ": { ";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : ", ");
    }
    std::cout << " }" << std::endl;
}

int main()
{
    std::cout << "===== Testando Algoritmos de Ordenacao com Vetores Pequenos =====" << std::endl << std::endl;

    // Definindo alguns vetores de teste
    std::vector<int> vet_original1 = {5, 1, 4, 2, 8};
    std::vector<int> vet_original2 = {3, 1, 2};
    std::vector<int> vet_original3 = {1, 2, 3, 4, 5};    // Já ordenado
    std::vector<int> vet_original4 = {5, 4, 3, 2, 1};    // Ordem reversa
    std::vector<int> vet_original5 = {};                 // Vazio
    std::vector<int> vet_original6 = {7};                // Um elemento
    std::vector<int> vet_original7 = {2, 3, 2, 1, 3, 1}; // Com duplicatas

    std::vector<std::vector<int>> test_vectors = {
        vet_original1, vet_original2, vet_original3, vet_original4,
        vet_original5, vet_original6, vet_original7};

    // Ponteiros para as funções de ordenação para facilitar o loop
    typedef std::vector<long long> (*SortFunc)(std::vector<int> &, int);
    std::vector<std::pair<std::string, SortFunc>> sorting_algorithms = {
        {"BubbleSortOptimized", BubbleSortOptimized},
        {"BubbleSort", BubbleSort},
        {"InsertionSort", InsertionSort},
        {"SelectionSortOptimized", SelectionSortOptimized},
        {"SelectionSort", SelectionSort}};

    int test_case_num = 1;
    for (const auto &original_vet : test_vectors)
    {
        std::cout << "--- Caso de Teste " << test_case_num++ << " ---" << std::endl;
        printVector("Vetor Original", original_vet);

        for (const auto &algo_pair : sorting_algorithms)
        {
            std::string algo_name = algo_pair.first;
            SortFunc sort_function = algo_pair.second;

            std::vector<int> vet_to_sort = original_vet; // Copia para não modificar o original

            std::cout << "\n  Aplicando " << algo_name << "..." << std::endl;
            std::vector<long long> stats = sort_function(vet_to_sort, vet_to_sort.size());

            printVector("  Vetor Ordenado", vet_to_sort);
            if (stats.size() == 2)
            {
                std::cout << "  Trocas: " << stats[0] << ", Comparacoes: " << stats[1] << std::endl;
            }
            else
            {
                std::cout << "  Erro: Estatisticas nao retornadas corretamente." << std::endl;
            }

            // Verificação simples de ordenação
            std::vector<int> verification_vet = original_vet;
            if (!verification_vet.empty())
            {
                std::sort(verification_vet.begin(), verification_vet.end()); // Usa std::sort como referência
            }
            if (vet_to_sort == verification_vet)
            {
                std::cout << "  Status: Ordenacao CORRETA." << std::endl;
            }
            else
            {
                std::cout << "  Status: Ordenacao INCORRETA." << std::endl;
                printVector("  Esperado (std::sort)", verification_vet);
            }
        }
        std::cout << "------------------------------------" << std::endl << std::endl;
    }

    std::cout << "\n===== Testando Algoritmos de Busca com Vetores Pequenos =====" << std::endl << std::endl;

    std::vector<int> vet_para_busca_nao_ordenado = {50, 10, 40, 20, 80, 70, 30, 60};
    std::vector<int> vet_para_busca_ordenado = vet_para_busca_nao_ordenado;
    // Usando uma de suas funções de ordenação para preparar para a busca binária
    BubbleSortOptimized(vet_para_busca_ordenado, vet_para_busca_ordenado.size());

    printVector("Vetor para Busca (Nao Ordenado)", vet_para_busca_nao_ordenado);
    printVector("Vetor para Busca (Ordenado)", vet_para_busca_ordenado);
    std::cout << std::endl;

    int alvos_busca[] = {20, 77, 50, 10, 80, 99}; // Elementos para buscar (existentes e inexistentes)

    std::cout << "--- Testando Busca Linear ---" << std::endl;
    for (int alvo : alvos_busca)
    {
        std::vector<long long> resultado_busca = linearSearch(alvo, vet_para_busca_nao_ordenado, vet_para_busca_nao_ordenado.size());
        long long indice_encontrado = -1;
        long long comparacoes = -1;
        if (!resultado_busca.empty())
            indice_encontrado = resultado_busca[0];
        if (resultado_busca.size() > 1)
            comparacoes = resultado_busca[1];

        if (indice_encontrado != -1)
        {
            std::cout << "  LinearSearch: Elemento " << alvo << " encontrado no indice " << indice_encontrado << ". (Comparacoes: " << comparacoes << ")" << std::endl;
        }
        else
        {
            std::cout << "  LinearSearch: Elemento " << alvo << " NAO encontrado. (Comparacoes: " << comparacoes << ")" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "--- Testando Busca Binaria (requer vetor ordenado) ---" << std::endl;
    std::cout << "  Testando em vetor CORRETAMENTE ordenado:" << std::endl;
    for (int alvo : alvos_busca)
    {
        std::vector<long long> resultado_busca = binarySearch(alvo, vet_para_busca_ordenado, vet_para_busca_ordenado.size());
        long long indice_encontrado = -1;
        long long comparacoes = -1;
        if (!resultado_busca.empty())
            indice_encontrado = resultado_busca[0];
        if (resultado_busca.size() > 1)
            comparacoes = resultado_busca[1];

        if (indice_encontrado != -1)
        {
            std::cout << "    BinarySearch: Elemento " << alvo << " encontrado no indice " << indice_encontrado << ". (Comparacoes: " << comparacoes << ")" << std::endl;
        }
        else
        {
            std::cout << "    BinarySearch: Elemento " << alvo << " NAO encontrado. (Comparacoes: " << comparacoes << ")" << std::endl;
        }
    }
    std::cout << std::endl;

    std::cout << "  Testando em vetor NAO ordenado (comportamento pode ser inesperado):" << std::endl;
    int alvo_teste_nao_ordenado = 20;
    std::vector<long long> resultado_busca_nao_ord = binarySearch(alvo_teste_nao_ordenado, vet_para_busca_nao_ordenado, vet_para_busca_nao_ordenado.size());
    long long indice_encontrado_nao_ord = -1;
    long long comparacoes_nao_ord = -1;
    if (!resultado_busca_nao_ord.empty())
        indice_encontrado_nao_ord = resultado_busca_nao_ord[0];
    if (resultado_busca_nao_ord.size() > 1)
        comparacoes_nao_ord = resultado_busca_nao_ord[1];

    if (indice_encontrado_nao_ord != -1 && static_cast<size_t>(indice_encontrado_nao_ord) < vet_para_busca_nao_ordenado.size() && vet_para_busca_nao_ordenado[indice_encontrado_nao_ord] == alvo_teste_nao_ordenado)
    {
        std::cout << "    BinarySearch (em nao ordenado): Elemento " << alvo_teste_nao_ordenado << " encontrado no indice " << indice_encontrado_nao_ord << " (pode ser sorte ou erro). (Comparacoes: " << comparacoes_nao_ord << ")" << std::endl;
    }
    else if (indice_encontrado_nao_ord != -1)
    {
        std::cout << "    BinarySearch (em nao ordenado): Elemento " << alvo_teste_nao_ordenado << " NAO encontrado corretamente (indice " << indice_encontrado_nao_ord << "). (Comparacoes: " << comparacoes_nao_ord << ")" << std::endl;
    }
    else
    {
        std::cout << "    BinarySearch (em nao ordenado): Elemento " << alvo_teste_nao_ordenado << " NAO encontrado. (Comparacoes: " << comparacoes_nao_ord << ")" << std::endl;
    }
    std::cout << "------------------------------------" << std::endl << std::endl;

    std::cout << "===== Fim dos Testes =====" << std::endl;

    return 0;
}
*/
/*
Para compilar e executar este arquivo:

1. Certifique-se de que `algorithms.hpp` e `searches.hpp` estão corretos.
   Exemplo de `searches.hpp` (consistente com o retorno de std::vector<long long>):
   #ifndef SEARCHES_HPP
   #define SEARCHES_HPP
   #include <vector>
   std::vector<long long> linearSearch(int target, std::vector<int>& arr, int n);
   std::vector<long long> binarySearch(int target, std::vector<int>& arr, int n); // arr DEVE estar ordenado
   #endif

2. Certifique-se de que `algorithms.cpp` e `searches.cpp` estão implementados corretamente.
   Exemplo de `searches.cpp` (com contagem de comparações e retorno de std::vector<long long>):
   #include "searches.hpp"
   std::vector<long long> linearSearch(int target, std::vector<int>& arr, int n) {
       long long comparacoes = 0;
       for (int i = 0; i < n; ++i) {
           comparacoes++;
           if (arr[i] == target) return {static_cast<long long>(i), comparacoes};
       }
       return {-1LL, comparacoes}; // -1LL para indicar long long
   }
   std::vector<long long> binarySearch(int target, std::vector<int>& arr, int n) {
       long long comparacoes = 0;
       if (n == 0) return {-1LL, comparacoes};
       int low = 0, high = n - 1;
       while (low <= high) {
           int mid = low + (high - low) / 2;
           comparacoes++; // Comparação para igualdade
           if (arr[mid] == target) return {static_cast<long long>(mid), comparacoes};
           comparacoes++; // Comparação para decidir o lado
           if (arr[mid] < target) low = mid + 1;
           else high = mid - 1;
       }
       return {-1LL, comparacoes};
   }

3. Compile:
   g++ -std=c++11 main.cpp algorithms.cpp searches.cpp -o testador_pequeno

4. Execute:
   ./testador_pequeno

*/