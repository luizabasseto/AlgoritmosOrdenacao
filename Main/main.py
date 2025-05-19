from Algoritmos import algoritmosOrdenacao
from ManipulacaoArquivos import Arquivo
import time

def main():

    arquivo1 = Arquivo.Arquivo("Arquivo", 1000)
    arquivo1.createArquivoBin()

    lista1 = arquivo1.ReadArquivoBin()
    lista = algoritmosOrdenacao.Algoritmos(lista1,1000)

    inicio = time.time()
    lista.BubbleSortPuro()
    fim = time.time()

    print(fim-inicio)
    
main()    