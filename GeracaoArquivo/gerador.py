from random import randint

def GerarNumeros(n):
    lista= []
    for i in range(n):
        lista.append(randint(0,1000))
        
    return lista