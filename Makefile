# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Output executable
TARGET = matrix_program

# Source files
SRCS = main.cpp matrix.cpp

# Header files
HEADERS = matrix.hpp

# Build target
$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean target
clean:
	rm -f $(TARGET)
