# Compiler
CC = gcc
CFLAGS = -Wall -Iinclude -fPIC

# Directories
SRC_DIR = src
BUILD_DIR = build
LIB_DIR = lib

# Library Names
STATIC_LIB = $(LIB_DIR)/libspinner.a
SHARED_LIB = $(LIB_DIR)/libspinner.so
OBJECTS = $(BUILD_DIR)/spinner.o

# Target to build both static and shared libraries
all: static shared

# Compile object files
$(BUILD_DIR)/spinner.o: $(SRC_DIR)/spinner/spinner.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create Static Library (.a)
static: $(OBJECTS) | $(LIB_DIR)
	ar rcs $(STATIC_LIB) $(OBJECTS)

# Create Shared Library (.so)
shared: $(OBJECTS) | $(LIB_DIR)
	$(CC) -shared -o $(SHARED_LIB) $(OBJECTS)

# Run using Static Library
run_static: static
	$(CC) -o $(BUILD_DIR)/test_static test/main.c -L$(LIB_DIR) -lspinner -Iinclude
	./$(BUILD_DIR)/test_static

# Run using Shared Library
run_shared: shared
	$(CC) -o $(BUILD_DIR)/test_shared test/main.c -L$(LIB_DIR) -lspinner -Iinclude
	export LD_LIBRARY_PATH=$(LIB_DIR):$$LD_LIBRARY_PATH && ./$(BUILD_DIR)/test_shared

# Create necessary directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)
