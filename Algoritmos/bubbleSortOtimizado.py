def BubbleSortOtimizado(lista):
    n = len(lista)
    swapped = False
    for i in range(n):
        for j in range(n-1-i):
            if lista[j] > lista[j + 1]:
                lista[j],lista[j+1] = lista[j+1],lista[j]
                swapped = True
        if(~swapped):
            break
            

    for i in range(n):
        if lista[n]>lista[n+1]:
            return False

    return True
