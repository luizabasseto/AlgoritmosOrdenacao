from Algoritmos import algoritmosOrdenacao
from ManipulacaoArquivos import Arquivo
from Buscas import Buscas
import time

def main():

    #Algoritmo BubbleSort Puro com tamanho 1000
    arquivo1 = Arquivo.Arquivo("ArquivoBubbleP", 1000)
    arquivo1.createArquivoBin()
    lista1BubbleP = arquivo1.ReadArquivoBin()
    lista1BubbleP = algoritmosOrdenacao.Algoritmos(lista1BubbleP,1000)
    lista1BubblePBusca = Buscas.Buscas(lista1BubbleP, 1000)
    lista1BubblePBusca.buscaLinear(4)
    inicio = time.time()
    lista1BubbleP.BubbleSortPuro()
    fim = time.time()

    print(fim-inicio)
    
    #Algoritmo BubbleSortOtimizado com tamanho 1000
    arquivo1 = Arquivo.Arquivo("ArquivoBubbleO", 1000)
    arquivo1.createArquivoBin()
    lista1BubbleO = arquivo1.ReadArquivoBin()
    lista1BubbleO = algoritmosOrdenacao.Algoritmos(lista1BubbleO,1000)
    inicio = time.time()
    lista1BubbleO.BubbleSortOtimizado()
    fim = time.time()
    print(fim-inicio)
    
    