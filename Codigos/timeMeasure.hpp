#include <vector>
#include <string>
#include <iostream>

using namespace std;

void timeMean(void (*sortFunc)(vector<int>&, int), vector<int> vet, int n, const string& nome);

void timeSearch(int (*searchFunc)(int, std::vector<int>&, int), int elem, std::vector<int> vet, int n, const std::string& nome);