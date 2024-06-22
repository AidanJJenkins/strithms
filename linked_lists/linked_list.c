#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

List *init() {
  List *l = malloc(sizeof(List));
  l->count = 0;
  l->head = NULL;
  l->tail = NULL;

  return l;
}

Node *create_node(int val) {
  Node *n = malloc(sizeof(Node));
  n->val = val;
  n->next = NULL;

  return n;
}

void append(List *l, int val) {
  Node *n = create_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;

    return;
  }

  l->tail->next = n;
  l->tail = n;
}

void prepend(List *l, int val) {
  Node *n = create_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;

    return;
  }

  n->next = l->head;
  l->head = n;
}

int get(List *l, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    return -1;
  }

  Node *curr = l->head;
  for (int i = 0; i < idx; i++) {
    curr = curr->next;
  }

  return curr->val;
}
int remove_at(List *l, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    return -1;
  }

  if (idx == 0) {
    Node *temp = l->head;
    int out = temp->val;
    l->head = l->head->next;

    free(temp);
    l->count--;
    return out;
  }

  Node *prev = l->head;
  Node *curr = l->head->next;
  int i = 1;

  while (curr != NULL) {
    if (idx == i) {
      Node *temp = curr;
      int out = curr->val;
      prev->next = curr->next;
      l->count--;

      free(temp);
      return out;
    }

    prev = prev->next;
    curr = curr->next;
    i++;
  }

  return -1;
}

void insert_at(List *l, int val, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    printf("Idx out of range");
    return;
  } else if (idx <= 0) {
    prepend(l, val);
    return;
  } else if (idx == l->count) {
    append(l, val);
    return;
  }

  Node *prev = l->head;
  Node *curr = l->head->next;
  int i = 1;

  while (curr != NULL) {
    if (i == idx) {
      Node *new = create_node(val);
      prev->next = new;
      new->next = curr;
      l->count++;
    }

    i++;
    prev = prev->next;
    curr = curr->next;
  }
}

int remove_val(List *l, int val) {
  if (l->head == NULL || l->head == NULL) {
    return -1;
  }

  if (l->head->val == val) {
    Node *temp = l->head;
    int out = temp->val;
    l->head = l->head->next;

    free(temp);
    l->count--;
    return out;
  }

  Node *prev = l->head;
  Node *curr = l->head->next;

  while (curr != NULL) {
    if (curr->val == val) {
      Node *temp = curr;
      int out = curr->val;
      prev->next = curr->next;
      l->count--;

      free(temp);
      return out;
    }

    prev = prev->next;
    curr = curr->next;
  }

  return -1;
}

void print_list(List *l) {
  Node *curr = l->head;

  while (curr != NULL) {
    printf("current value: %d\n", curr->val);
    curr = curr->next;
  }
}
