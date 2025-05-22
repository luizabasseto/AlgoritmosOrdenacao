# Diretórios
SRCDIR := .
BUILDDIR := build
BINDIR := ../Archives

# Nome do executável
NAME := main
TARGET := $(BUILDDIR)/$(NAME)

# Fontes, objetos e dependências
SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))
DEP := $(OBJ:.o=.d)

# Compilador e flags
CXX := g++
CXXFLAGS := -Wall -std=c++11 -MMD -MP -m64
LD := $(CXX)
LDFLAGS := -m64

# Regras principais
.PHONY: all clean rebuild create_dirs install run

all: create_dirs $(TARGET)

$(TARGET): $(OBJ)
	@echo "Linkando $@..."
	$(LD) $(OBJ) -o $@ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "Compilando $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

create_dirs:
	@mkdir -p $(BUILDDIR) $(BINDIR)

install: all
	@cp $(TARGET) $(BINDIR)/

run: all
	@echo "Executando $(TARGET)..."
	@./$(TARGET)

clean:
	@echo "Limpando arquivos..."
	@rm -rf $(BUILDDIR) $(TARGET)

rebuild: clean all

# Inclusão de dependências (auto geradas com -MMD -MP)
-include $(DEP)
