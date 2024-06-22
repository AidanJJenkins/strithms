CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executables
TARGETS = test_doubly_linked_list test_linked_list test_reverse_list

# Source files
DOUBLY_LINKED_LIST_SRCS = doubly_linked_list.c test_doubly_linked_list.c
LINKED_LIST_SRCS = linked_list.c test_linked_list.c
REVERSE_LIST_SRCS = reverse_list.c test_reverse_list.c 

# Object files
DOUBLY_LINKED_LIST_OBJS = $(DOUBLY_LINKED_LIST_SRCS:.c=.o)
LINKED_LIST_OBJS = $(LINKED_LIST_SRCS:.c=.o)
REVERSE_LIST_OBJS = $(REVERSE_LIST_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_doubly_linked_list executable
test_doubly_linked_list: $(DOUBLY_LINKED_LIST_OBJS)
	$(CC) $(CFLAGS) -o test_doubly_linked_list $(DOUBLY_LINKED_LIST_OBJS)

# Link the test_linked_list executable
test_linked_list: $(LINKED_LIST_OBJS)
	$(CC) $(CFLAGS) -o test_linked_list $(LINKED_LIST_OBJS)

test_reverse_list: $(REVERSE_LIST_OBJS)
	$(CC) $(CFLAGS) -o test_reverse_list $(REVERSE_LIST_OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(DOUBLY_LINKED_LIST_OBJS) $(LINKED_LIST_OBJS) $(REVERSE_LIST_OBJS) $(TARGETS)

# Individual test targets
linked_list: test_linked_list
	./test_linked_list

doubly_linked_list: test_doubly_linked_list
	./test_doubly_linked_list

reverse_list: test_reverse_list
	./test_reverse_list

# Phony targets
.PHONY: all clean linked_list doubly_linked_list reverse_list

