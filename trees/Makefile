CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I..
VPATH = ../common

# Target executables
TARGETS = test_order test_bst test_comp test_btbfs test_invert test_minheap

# Source files
ORDER_SRCS = order.c test_order.c vec.c
BST_SRCS = bst.c test_bst.c
COMP_SRCS = compare_trees.c test_compare_trees.c
BTBFS_SRCS = btbfs.c test_btbfs.c
INVERT_SRCS = invert.c test_invert.c bst.c
MINHEAP_SRCS = minheap.c test_minheap.c vec.c

# Object files
ORDER_OBJS = $(ORDER_SRCS:.c=.o)
BST_OBJS = $(BST_SRCS:.c=.o)
COMP_OBJS = $(COMP_SRCS:.c=.o)
INVERT_OBJS = $(INVERT_SRCS:.c=.o)
MINHEAP_OBJS = $(MINHEAP_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_order executable
test_order: $(ORDER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_bst: $(BST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_comp: $(COMP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_btbfs: $(BTBFS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_invert: $(INVERT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_minheap: $(MINHEAP_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(ORDER_OBJS) $(BST_OBJS) $(COMP_OBJS) $(BTBFS_OBJS) $(INVERT_OBJS) $(MINHEAP_OBJS) $(TARGETS)

# Run the test
order: test_order
	./test_order

bst: test_bst
	./test_bst

comp: test_comp
	./test_comp

btbfs: test_btbfs
	./test_btbfs

invert: test_invert
	./test_invert

minheap: test_minheap
	./test_minheap

# Phony targets
.PHONY: all clean run
