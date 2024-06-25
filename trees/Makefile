CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I..
VPATH = ../common

# Target executables
TARGETS = test_order test_bst

# Source files
ORDER_SRCS = order.c test_order.c vec.c
BST_SRCS = bst.c test_bst.c

# Object files
ORDER_OBJS = $(ORDER_SRCS:.c=.o)
BST_OBJS = $(BST_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_order executable
test_order: $(ORDER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

test_bst: $(BST_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(ORDER_OBJS) $(BST_OBJS)$(TARGETS)

# Run the test
run: test_order
	./test_order

bst: test_bst
	./test_bst

# Phony targets
.PHONY: all clean run
