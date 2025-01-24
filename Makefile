# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Source file
SRC = resource_leak.c

# Output executable
OUT = resource_leak

# Default target
all: $(OUT)

# Rule to compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean up object files and the executable
clean:
	rm -f $(OUT)

# Phony targets
.PHONY: all clean
