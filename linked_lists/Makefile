# Compiler and flags
CC = gcc
CFLAGS = -std=c11

# Targets
all: test_doubly_linked_list test_stack test_queue

# Compile and run tests for doubly linked list
test_doubly_linked_list: doubly_linked_list.o test_doubly_linked_list.o
	$(CC) $(CFLAGS) -o test_doubly_linked_list doubly_linked_list.o test_doubly_linked_list.o
	./test_doubly_linked_list

test_stack: stack.o test_stack.o
	$(CC) $(CFLAGS) -o test_stack stack.o test_stack.o
	./test_stack

test_queue: queue.o test_queue.o
	$(CC) $(CFLAGS) -o test_queue queue.o test_queue.o
	./test_queue

# Compile source files
doubly_linked_list.o: doubly_linked_list.c doubly_linked_list.h
	$(CC) $(CFLAGS) -c doubly_linked_list.c

test_doubly_linked_list.o: test_doubly_linked_list.c doubly_linked_list.h
	$(CC) $(CFLAGS) -c test_doubly_linked_list.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

test_stack.o: test_stack.c stack.h
	$(CC) $(CFLAGS) -c test_stack.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

test_queue.o: test_queue.c queue.h
	$(CC) $(CFLAGS) -c test_queue.c

# Clean up
clean:
	rm -f *.o test_doubly_linked_list test_stack test_queue

.PHONY: all clean
