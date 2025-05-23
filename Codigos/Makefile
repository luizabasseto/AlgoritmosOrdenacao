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

all: $(TARGET)

$(TARGET): $(OBJ)
	if not exist $(BINDIR) mkdir $(BINDIR)
	$(CXX) $(OBJ) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	-del /Q $(BUILDDIR)\*.o 2>nul || exit 0
	-del /Q $(TARGET) 2>nul || exit 0 