# Diretórios
SRCDIR := .
BUILDDIR := build
BINDIR := ../Archives

# Nome do executável
NAME := main.exe
TARGET := $(BUILDDIR)/$(NAME)

# Fontes e objetos
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

# Compilador
CXX := g++
CXXFLAGS := -Wall -std=c++11
LDFLAGS := 

# Regras principais
.PHONY: all clean rebuild create_dirs install run

all: create_dirs $(TARGET)

# Linkagem
$(TARGET): $(OBJ)
	@echo Linkando $(TARGET)...
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compilação dos arquivos .cpp
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Criação de diretórios
create_dirs:
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	@if not exist $(BINDIR) mkdir $(BINDIR)

# Instala o executável no diretório de binários
install: all
	copy $(TARGET) $(BINDIR)\

# Executa o programa
run: all
	$(TARGET)

# Limpeza dos arquivos compilados
clean:
	@echo Limpando arquivos...
	@if exist $(BUILDDIR) del /Q $(BUILDDIR)\*.o
	@if exist $(TARGET) del /Q $(TARGET)

# Reconstrói tudo
rebuild: clean all