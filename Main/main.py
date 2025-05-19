from Algoritmos import algoritmosOrdenacao
from ManipulacaoArquivos import Arquivo

def main():

    arquivo1 = Arquivo.__init__("Arquivo1", 1000)
    arquivo1.createArquivoBin()

    lista1 = arquivo1.ReadArquivoBin()
    lista = Algoritmos.__init__(lista1,1000)

    lista.BubbleSortPuro()


    




    
    
main()    