# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-unused-variable

# Directories
SRC_DIR = src
BUILD_DIR = build

# Find all .c files in src and subdirectories
SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Output binary
TARGET = $(BUILD_DIR)/main

# Default rule
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(OBJS) -o $(TARGET)

# Compile each .c file into an .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Run the program
# echo "duckui" | ./$(TARGET) -a
run: all
	#NOTE: you have to create these files if you want to test this.
	./$(TARGET) --help ../index.ts ../max.ts
