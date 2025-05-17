
lista = []

def BubbleSortPuro(lista):
    n = len(lista)
    for i in range(n):
        for j in range(n-1-i):
            if lista[j] > lista[j + 1]:
                temp = lista[j+1]
                lista[j+1] = lista[j]
                lista[j] = temp

    for i in range(n-1):
        if lista[n]>lista[n+1]:
            return False

    return True
