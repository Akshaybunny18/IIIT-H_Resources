# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c99

# Target executable name
TARGET = program

# Source files
SRCS = main.c math_ops.c

# Object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Default target to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files and the executable
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)