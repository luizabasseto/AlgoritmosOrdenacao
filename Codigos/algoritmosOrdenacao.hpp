#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
bool verificarOrdenacao(vector<T> &lista, int n);

template<typename T>
bool BubbleSortOtimizado(vector<T> &lista, int n);

template<typename T>
bool BubbleSortPuro(vector<T> &lista, int n);

template<typename T>
bool InsertionSort(vector<T> &lista, int n);

template<typename T>
bool SelectionSort(vector<T> &lista, int n);


#endif
