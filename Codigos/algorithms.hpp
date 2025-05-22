#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool BubbleSortOptimized(vector<T> &vet, int n);

template<typename T>
bool BubbleSort(vector<T> &vet, int n);

template<typename T>
bool InsertionSort(vector<T> &vet, int n);

template<typename T>
bool InsertionSortOptimized(vector<T> &vet, int n);

template<typename T>
bool SelectionSort(vector<T> &vet, int n);


#endif
