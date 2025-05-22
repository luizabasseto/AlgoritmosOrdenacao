SRCDIR := .
BUILDDIR := build
BINDIR := ../Archives
TARGET := $(BUILDDIR)/main.exe

SRC := $(wildcard $(SRCDIR)/*.cpp)
OBJ := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))

CXX := g++
CXXFLAGS := -Wall -std=c++11

all: create_dirs $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

create_dirs:
	if not exist "$(BUILDDIR)" mkdir "$(BUILDDIR)"
	if not exist "$(BINDIR)" mkdir "$(BINDIR)"

clean:
	del /Q $(BUILDDIR)\*.o $(TARGET)
