#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void reverse_i(List *l) {
  Node *prev = NULL;
  Node *current = l->head;
  Node *next = NULL;
  l->tail = l->head;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  l->head = prev;
}
void reverse_recursive_helper(Node *current, Node *prev, List *l) {
  if (current == NULL) {
    l->head = prev;
    return;
  }

  Node *next = current->next;
  current->next = prev;
  reverse_recursive_helper(next, current, l);
}

void reverse_r(List *l) {
  l->tail = l->head;
  reverse_recursive_helper(l->head, NULL, l);
}
