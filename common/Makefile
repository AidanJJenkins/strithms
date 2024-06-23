CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Target executables
TARGETS = test_vec

# Source files
VEC_SRCS = vec.c test_vec.c

# Object files
VEC_OBJS = $(VEC_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_doubly_linked_list executable
test_vec: $(VEC_OBJS)
	$(CC) $(CFLAGS) -o test_vec $(VEC_OBJS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(VEC_OBJS) $(TARGETS)

# Individual test targets
vec: test_vec
	./test_vec


# Phony targets
.PHONY: all clean vec

