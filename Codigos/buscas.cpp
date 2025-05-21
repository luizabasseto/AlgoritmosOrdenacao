#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int buscaBinaria(int elemento, vector<T> &lista, int n)
{
    int j = n/2;
    for (int i = 0; i < n; i++)
    {
        if(lista[j]>elemento){
            for (int k = j; k < n; k++)
            {
                j= j/2;
                if (lista[j]>elemento)
                {
                    
                }
                
            }
            
        }else{

        }
    }
    

    return -1;
}

template <typename T>
int buscaLinear(int elemento, vector<T> &lista, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (lista[i] == elemento)
        {
            return i;
        }
    }
    return -1;
};