# Compiler and flags
CC      := gcc
CFLAGS  := -Wall -std=c99 -Iinclude
LDFLAGS := -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

# Source / output
SRC     := main.c
TARGET  := wordle.exe

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

# Cleanup
clean:
	rm -f $(TARGET)
