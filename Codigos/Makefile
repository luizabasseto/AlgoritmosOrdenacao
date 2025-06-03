SRCDIR := .
BUILDDIR := build
BINDIR := ../Archives

NAME := main.exe
TARGET := $(BUILDDIR)/$(NAME)

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp, $(BUILDDIR)/%.o, $(SRC))

CXX := g++
CXXFLAGS := -Wall -std=c++11
LDFLAGS := 

.PHONY: all clean rebuild create_dirs install run

all: create_dirs $(TARGET)

$(TARGET): $(OBJ)
	@echo Linkando $(TARGET)...
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

create_dirs:
	@if not exist $(BUILDDIR) mkdir $(BUILDDIR)
	@if not exist $(BINDIR) mkdir $(BINDIR)

install: all
	copy $(TARGET) $(BINDIR)\

run: all
	$(TARGET)

clean:
	@echo Limpando arquivos...
	@if exist $(BUILDDIR) del /Q $(BUILDDIR)\*.o
	@if exist $(TARGET) del /Q $(TARGET)

rebuild: clean all