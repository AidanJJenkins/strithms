# CC = gcc
# CFLAGS = -Wall -Wextra -std=c11
#
# # Target executables
# TARGETS = order
#
# # Source files
# ORDER_SRCS = order.c test_order.c
#
# # Object files
# ORDER_OBJS = $(ORDER_SRCS:.c=.o)
#
# # Default target
# all: $(TARGETS)
#
# # Link the test_doubly_linked_list executable
# test_order: $(ORDER_OBJS)
# 	$(CC) $(CFLAGS) -o test_order $(ORDER_OBJS)
#
# # Compile source files to object files
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@
#
# # Clean up build files
# clean:
# 	rm -f $(ORDER_OBJS) $(TARGETS)
#
# # Individual test targets
# order: test_order
# 	./test_order
#
#
# # Phony targets
# .PHONY: all clean order
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I..
VPATH = ../common

# Target executables
TARGETS = test_order

# Source files
ORDER_SRCS = order.c test_order.c vec.c

# Object files
ORDER_OBJS = $(ORDER_SRCS:.c=.o)

# Default target
all: $(TARGETS)

# Link the test_order executable
test_order: $(ORDER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(ORDER_OBJS) $(TARGETS)

# Run the test
run: test_order
	./test_order

# Phony targets
.PHONY: all clean run
