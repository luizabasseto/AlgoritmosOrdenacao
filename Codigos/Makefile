# Diretórios
SRCDIR := .
BUILDDIR := build
BINDIR := ../Archives
TARGET := $(BUILDDIR)/main.exe

# Fontes e objetos
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))

# Compilador
CXX := g++
CXXFLAGS := -Wall -std=c++11

# Regras
all: $(TARGET)

# Regra principal
$(TARGET): $(OBJ)
	if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(OBJ) -o $@

# Compilação de .cpp em .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	-del /Q $(BUILDDIR)\*.o 2>nul || exit 0
	-del /Q $(TARGET) 2>nul || exit 0
