import gerador.py from Geração de Arquivo

def createArquivoBin(n):
    nameArquivo = "ArquivoTamanho"+n
    with open (nameArquivo,'wb') as arquivo:
        for i in range(n):
            arquivo.write(gerarNumeros())