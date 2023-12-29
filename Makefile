# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
LIB_DIR = lib

# Source files and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Executable name
EXECUTABLE = flappy

# Raylib files
RAYLIB_INCLUDE = $(INCLUDE_DIR)/raylib.h
RAYLIB_LIBRARY = $(LIB_DIR)/libraylib.a

# Main target
$(EXECUTABLE): $(OBJECTS) $(RAYLIB_LIBRARY)
	$(CXX) $(CXXFLAGS) $^ -o $@ -framework OpenGL -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT

# Rule to compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -I$(INCLUDE_DIR) $< -o $@

# Clean rule to remove generated files
clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

# Phony target to avoid conflicts with file names
.PHONY: clean

# Raylib library rule
$(RAYLIB_LIBRARY):
	$(MAKE) -C $(LIB_DIR) RAYLIB_PATH=../$(LIB_DIR)

run: $(EXECUTABLE)
	./$(EXECUTABLE)