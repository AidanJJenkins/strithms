#include "../../include/group_one/linkedlist.h"
#include <stdlib.h>

List *init() {
  List *l = (List *)malloc(sizeof(List));
  l->head = NULL;
  l->tail = NULL;
  l->count = 0;

  return l;
}

Node *create_node(int val) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->val = val;
  n->next = NULL;

  return n;
}

void append(struct list *l, int val) {
  struct node *n = create_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    return;
  }

  l->tail->next = n;
  l->tail = n;
}

void prepend(struct list *l, int val) {
  struct node *n = create_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    return;
  }

  n->next = l->head;
  l->head = n;
}

int remove_val(struct list *l, int val) {
  if (l == NULL || l->head == NULL) {
    return -1;
  }

  Node *prev = NULL;
  Node *curr = l->head;

  if (curr->val == val) {
    l->head = curr->next;
    if (l->head == NULL) {
      l->tail = NULL;
    }
    int data = curr->val;
    free(curr);
    l->count--;
    return data;
  }

  prev = curr;
  curr = curr->next;
  while (curr != NULL) {
    if (curr->val == val) {
      prev->next = curr->next;
      if (l->tail == curr) {
        l->tail = prev;
      }
      int data = curr->val;
      free(curr);
      l->count--;
      return data;
    }
    prev = curr;
    curr = curr->next;
  }

  return -1;
}

void print_list(struct list *l) {
  struct node *current = l->head;
  while (current != NULL) {
    printf("curr: %d\n", current->val);
    current = current->next;
  }
}
