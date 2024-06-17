#include "../../include/group_one/stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void init_stack(stack *s) {
  s->count = 0;
  s->head = NULL;
}

void push(stack *s, void *data) {
  node *new_node = (node *)malloc(sizeof(node));
  assert(new_node);

  new_node->val = data;
  new_node->next = s->head;
  s->head = new_node;
  s->count++;
}

void *pop(stack *s) {
  assert(s->count > 0);
  node *temp = s->head;
  void *out = temp->val;

  s->head = temp->next;
  s->count--;

  free(temp);
  return out;
}

void *peek(stack *s) {
  assert(s->count > 0);
  return s->head->val;
}
