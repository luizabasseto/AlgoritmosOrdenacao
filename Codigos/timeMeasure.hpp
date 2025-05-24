#include <vector>
#include <string>
#include <iostream>

using namespace std;

void timeMean(std::vector<int> (*func)(std::vector<int>&, int), std::vector<int> vet, int n, const std::string& nome);

void timeSearch(std::vector<int> (*searchFunc)(int, std::vector<int>&, int), int elem, std::vector<int> vet, int n, const std::string& nome);