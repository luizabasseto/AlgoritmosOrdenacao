from GeracaoNumero import gerador;

class Arquivo:
    def __init__(self, name, size):
        self.__name = name
        self.__size = size
    

    def createArquivoBin(self):
        self.__name = self.__name + str(self.__size) +".bin"
        with open (self.__name,'wb') as arquivo:
            for i in range(self.__size):
                arquivo.write(gerador.GerarNumeros(self.__size))
                
    def ReadArquivoBin(self):
        lista = []
        with open(self.__name, 'rb') as arquivo:
            for i in range(self.__size):
                bytes_lidos = arquivo.read(4)
                if bytes_lidos:
                    num = int.from_bytes(bytes_lidos, byteorder='little')
                    lista.append(num)
        return lista