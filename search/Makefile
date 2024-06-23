CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executables
TARGETS = test_binary_search
TARGETS = test_linear_search

# Source files
BINARY_SRCS = binary_search.c test_binary_search.c
LINEAR_SRCS = linear_search.c test_linear_search.c

# Object files
BINARY_OBJS = $(BINARY_SRCS:.c=.o)
LINEAR_OBJS = $(LINEAR_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_doubly_linked_list executable
test_binary_search: $(BINARY_OBJS)
	$(CC) $(CFLAGS) -o test_binary_search $(BINARY_OBJS)

test_linear_search: $(LINEAR_OBJS)
	$(CC) $(CFLAGS) -o test_linear_search $(LINEAR_OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(BINARY_OBJS) $(LINEAR_OBJS) $(TARGETS)

# Individual test targets
binary_search: test_binary_search
	./test_binary_search

linear_search: test_linear_search
	./test_linear_search

# Phony targets
.PHONY: all clean binary_search
