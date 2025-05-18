import gerador.py from GeracaoArquivo

class Arquivo:
    def __init__(self, name, size):
        self.__name = name
        self.__size = size
    

    def createArquivoBin(self):
        nameArquivo = "ArquivoTamanho"+self.__size
        with open (nameArquivo,'wb') as arquivo:
            for i in range(self.__size):
                arquivo.write(gerarNumeros())
        return True
                
    def ReadArquivoBin(self):
        lista=[]
        with open (self.__name,'rb') as arquivo:
            for i in range(self.__size):
                lista.append(arquivo.read())
        return lista