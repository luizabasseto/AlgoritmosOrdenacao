from GeracaoNumero import gerador;

class Arquivo:
    def __init__(self, name, size):
        self.__name = name
        self.__size = size
    

    def createArquivoBin(self):
        self.__name = self.__name + str(self.__size) +".bin"
        numeros = gerador.GerarNumeros(self.__size)
        with open (self.__name,'wb') as arquivo:
            for numero in numeros:
                arquivo.write(numero.to_bytes(4, byteorder='little'))
                
    def ReadArquivoBin(self):
        lista = []
        with open(self.__name, 'rb') as arquivo:
            for i in range(self.__size):
                bytes_lidos = arquivo.read(4)
                if bytes_lidos:
                    num = int.from_bytes(bytes_lidos, byteorder='little')
                    lista.append(num)
        return lista