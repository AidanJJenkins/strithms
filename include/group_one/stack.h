#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void *val;
  struct node *next;
} node;

typedef struct stack {
  int count;
  node *head;
} stack;

void init_stack(stack *s);
void push(stack *s, void *data);
void *pop(stack *s);
void *peek(stack *s);

#endif
