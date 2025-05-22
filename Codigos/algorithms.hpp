#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void BubbleSortOptimized(vector<T> &vet, int n);

template<typename T>
void BubbleSort(vector<T> &vet, int n);

template<typename T>
void InsertionSort(vector<T> &vet, int n);

template<typename T>
void InsertionSortOptimized(vector<T> &vet, int n);

template<typename T>
void SelectionSort(vector<T> &vet, int n);


#endif
