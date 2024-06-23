CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executables
TARGETS = test_quick_sort
TARGETS = test_bubblesort

# Source files
QUICK_SORT_SRCS = quick_sort.c test_quick_sort.c
BUBBLESORT_SRCS = bubblesort.c test_bubblesort.c

# Object files
QUICK_OBJS = $(QUICK_SORT_SRCS:.c=.o)
BUBBLE_OBJS = $(BUBBLESORT_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_doubly_linked_list executable
test_quick_sort: $(QUICK_OBJS)
	$(CC) $(CFLAGS) -o test_quick_sort $(QUICK_OBJS)

test_bubblesort: $(BUBBLE_OBJS)
	$(CC) $(CFLAGS) -o test_bubblesort $(BUBBLE_OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(QUICK_OBJS) $(BUBBLE_OBJS) $(TARGETS)

# Individual test targets
quick_sort: test_quick_sort
	./test_quick_sort

bubblesort: test_bubblesort
	./test_bubblesort

# Phony targets
.PHONY: all clean binary_search
