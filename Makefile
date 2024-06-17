# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -std=c11

# Directories
SRC_DIR = ./src/group_one
INCLUDE_DIR = ./include/group_one
TEST_DIR = ./tests/group_one

# Targets
all: group_one

# Group One Target
group_one: binary_search bubblesort linear_search stack

test_binary_search: $(SRC_DIR)/binary_search.c $(TEST_DIR)/binary_search.c
	$(CC) $(CFLAGS) -o binary_search $(SRC_DIR)/binary_search.c $(TEST_DIR)/binary_search.c
	./binary_search

# Compile and test bubble sort
test_bubblesort: $(SRC_DIR)/bubblesort.c $(TEST_DIR)/bubblesort.c
	$(CC) $(CFLAGS) -o bubblesort $(SRC_DIR)/bubblesort.c $(TEST_DIR)/bubblesort.c
	./bubblesort

test_linear_search: $(SRC_DIR)/linear_search.c $(TEST_DIR)/linear_search.c
	$(CC) $(CFLAGS) -o linear_search $(SRC_DIR)/linear_search.c $(TEST_DIR)/linear_search.c
	./linear_search

test_stack: $(SRC_DIR)/stack.c $(TEST_DIR)/stack.c
	$(CC) $(CFLAGS) -o stack $(SRC_DIR)/stack.c $(TEST_DIR)/stack.c
	./stack

# Clean up
clean:
	rm -f binary_search test_bubblesort linear_search stack

.PHONY: all group_one clean
