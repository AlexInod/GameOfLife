# Compiler and flagsa
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Target executable name
TARGET = Task1

# Source and header files
MAIN_SRC = Task1.c
FUNC_SRC = Task1func.c 
HEADER = Task1.h
OBJS = Task1.o Task1func.o

# Default target
all: $(TARGET)

# Rule to create the executable by linking object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main source file
Task1.o: $(MAIN_SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $(MAIN_SRC)

# Rule to compile functions source file
Task1func.o: $(FUNC_SRC) $(HEADER)
	$(CC) $(CFLAGS) -c $(FUNC_SRC)

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)

# Run rule (example with sample arguments)
# Usage: make run INPUT=input.txt OUTPUT=output_dir
run: $(TARGET)
	./$(TARGET) $(INPUT) $(OUTPUT)
# Phony targets
.PHONY: all clean run