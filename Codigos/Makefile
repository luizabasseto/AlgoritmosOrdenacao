# Diretórios
SRCDIR := .
BUILDDIR := build
BINDIR := ../Archives

# Detecta o sistema operacional
ifeq ($(OS),Windows_NT)
    EXE := .exe
    RM := del /Q /F
    MKDIR := if not exist $(1) mkdir $(1)
else
    EXE :=
    RM := rm -f
    MKDIR := mkdir -p $(1)
endif

TARGET := $(BUILDDIR)/main$(EXE)

# Fonte e objetos
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))

# Compilador
CXX := g++
CXXFLAGS := -Wall -std=c++11

# Regras
all: create_dirs $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

ifeq ($(OS),Windows_NT)
	create_dirs:
		@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
		@if not exist $(BINDIR) mkdir $(BINDIR)
else
	create_dirs:
		@mkdir -p $(BUILDDIR)
		@mkdir -p $(BINDIR)
endif
clean:
	-$(RM) $(BUILDDIR)/*.o
	-$(RM) $(TARGET)