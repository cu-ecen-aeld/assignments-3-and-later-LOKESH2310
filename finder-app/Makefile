# Makefile for writer application inside finder-app/

# Define variables
CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Werror
TARGET = writer
SRC = writer.c

# Default target
all: $(TARGET)

# Compile writer.c into writer
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean target to remove generated files
clean:
	rm -f $(TARGET) *.o

