#include "linkedlist.h"
#include <stdlib.h>

stack *init_stack() {
  stack *s = malloc(sizeof(stack));
  s->head = NULL;
  s->count = 0;

  return s;
}

Node *create_node(int val) {
  Node *n = malloc(sizeof(Node));

  n->val = val;
  n->next = NULL;
  return n;
}

void push(stack *s, int data) {
  Node *n = create_node(data);
  s->count++;

  if (s->head == NULL) {
    s->head = n;
    return;
  }

  n->next = s->head;
  s->head = n;
}

int pop(stack *s) {
  if (s->count == 0) {
    return -1;
  }

  Node *temp = s->head;
  int popped_value = temp->val;

  s->head = s->head->next;
  free(temp);

  s->count--;
  return popped_value;
}

int peek(stack *s) { return s->head->val; }
