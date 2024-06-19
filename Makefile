# Compiler and flags
CC = gcc
CFLAGS = -Iinclude -std=c11

# Directories
SRC_DIR = ./src
INCLUDE_DIR = ./include
TEST_DIR = ./tests

# Targets
all: group_one

# Group One Target
group_one: binary_search bubblesort linear_search stack queue linkedlist reverse_list quicksort doubly_linked_list

test_binary_search: $(SRC_DIR)/group_one/binary_search.c $(TEST_DIR)/group_one/binary_search.c
	$(CC) $(CFLAGS) -o binary_search $(SRC_DIR)/group_one/binary_search.c $(TEST_DIR)/group_one/binary_search.c
	./binary_search

test_bubblesort: $(SRC_DIR)/group_one/bubblesort.c $(TEST_DIR)/group_one/bubblesort.c
	$(CC) $(CFLAGS) -o bubblesort $(SRC_DIR)/group_one/bubblesort.c $(TEST_DIR)/group_one/bubblesort.c
	./bubblesort

test_linear_search: $(SRC_DIR)/group_one/linear_search.c $(TEST_DIR)/group_one/linear_search.c
	$(CC) $(CFLAGS) -o linear_search $(SRC_DIR)/group_one/linear_search.c $(TEST_DIR)/group_one/linear_search.c
	./linear_search

test_stack: $(SRC_DIR)/group_one/stack.c $(TEST_DIR)/group_one/stack.c
	$(CC) $(CFLAGS) -o stack $(SRC_DIR)/group_one/stack.c $(TEST_DIR)/group_one/stack.c
	./stack

test_queue: $(SRC_DIR)/group_one/queue.c $(TEST_DIR)/group_one/queue.c
	$(CC) $(CFLAGS) -o queue $(SRC_DIR)/group_one/queue.c $(TEST_DIR)/group_one/queue.c
	./queue

test_list: $(SRC_DIR)/group_one/linkedlist.c $(TEST_DIR)/group_one/linkedlist.c
	$(CC) $(CFLAGS) -o linkedlist $(SRC_DIR)/group_one/linkedlist.c $(TEST_DIR)/group_one/linkedlist.c
	./linkedlist

test_rev: $(SRC_DIR)/group_one/reverse_list.c $(TEST_DIR)/group_one/reverse_list.c
	$(CC) $(CFLAGS) -o reverse_list $(SRC_DIR)/group_one/reverse_list.c $(TEST_DIR)/group_one/reverse_list.c
	./reverse_list

test_quick_sort: $(SRC_DIR)/group_one/quick_sort.c $(TEST_DIR)/group_one/quick_sort.c
	$(CC) $(CFLAGS) -o quick_sort $(SRC_DIR)/group_one/quick_sort.c $(TEST_DIR)/group_one/quick_sort.c
	./quick_sort

test_double_list: $(SRC_DIR)/group_one/doubly_linked_list.c $(TEST_DIR)/group_one/doubly_linked_list.c
	$(CC) $(CFLAGS) -o doubly_linked_list $(SRC_DIR)/group_one/doubly_linked_list.c $(TEST_DIR)/group_one/doubly_linked_list.c
	./doubly_linked_list

test_vec: $(SRC_DIR)/group_one/vec.c $(TEST_DIR)/group_one/vec.c
	$(CC) $(CFLAGS) -o vec $(SRC_DIR)/group_one/vec.c $(TEST_DIR)/group_one/vec.c
	./vec

# Clean up
clean:
	rm -f binary_search bubblesort linear_search stack queue linkedlist reverse_list quick_sort doubly_linked_list

.PHONY: all group_one clean
