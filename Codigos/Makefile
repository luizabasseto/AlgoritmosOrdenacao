SRC_DIR = .
BUILD_DIR = build

CXX = g++
CXXFLAGS = -Wall -std=c++11

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

EXEC = $(BUILD_DIR)/main.exe

all: $(EXEC)

$(EXEC): $(OBJECTS)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)

run: all
	./$(EXEC)
