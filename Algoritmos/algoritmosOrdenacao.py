class Algoritmos:
    def __init__(self,lista,n):
        self.__lista = lista
        self.__n = n
        
    def BubbleSortOtimizado(self):
        n = len(self.__lista)
        lista = self.__lista
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
    
    def BubbleSortPuro(self):
        n = len(self.__n)
        lista = self.__lista
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