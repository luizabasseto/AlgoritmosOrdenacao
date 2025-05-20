CC = g++
CFLAGS = -c
OBJ = algoritmosOrdenacao.o buscas.o gerador.o manipulacaoArquivos.o main.o
EXEC = main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
