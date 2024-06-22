#include "linkedlist.h"
#include <stdlib.h>

d_list *init_d_list() {
  d_list *list = malloc(sizeof(d_list));
  list->head = NULL;
  list->tail = NULL;
  list->count = 0;

  return list;
}

d_node *init_d_node(int val) {
  d_node *n = malloc(sizeof(d_node));
  n->val = val;
  n->prev = NULL;
  n->next = NULL;
  return n;
}

void d_append(d_list *l, int val) {
  d_node *n = init_d_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    return;
  }

  l->tail->next = n;
  n->prev = l->tail;
  l->tail = n;
}

void d_prepend(d_list *l, int val) {
  d_node *n = init_d_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    return;
  }

  n->next = l->head;
  l->head->prev = n;
  l->head = n;
}

int remove_node(d_list *l, d_node *n) {
  if (l == NULL || n == NULL) {
    return -1;
  }

  if (l->count == 0) {
    return -1;
  }

  l->count--;

  if (l->count == 0) {
    int out = n->val;
    l->head = NULL;
    l->tail = NULL;

    free(n);
    return out;
  }

  if (n->prev != NULL) {
    n->prev->next = n->next;
  }

  if (n->next != NULL) {
    n->next->prev = n->prev;
  }

  if (l->head == n) {
    l->head = n->next;
  }

  if (l->tail == n) {
    l->tail = n->prev;
  }

  int out = n->val;
  free(n);

  return out;
}

d_node *get_at(d_list *l, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    return NULL;
  }

  d_node *curr = l->head;
  for (int i = 0; i < idx; i++) {
    curr = curr->next;
  }

  return curr;
}

void d_insert_at(d_list *l, int val, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    printf("idx out of range");
  } else if (idx == 0) {
    d_prepend(l, val);
    return;
  } else if (idx == l->count) {
    d_append(l, val);
    return;
  }

  l->count++;
  d_node *n = init_d_node(val);
  d_node *curr = get_at(l, idx);

  n->next = curr;
  n->prev = curr->prev;
  curr->prev = n;

  if (n->prev != NULL) {
    n->prev->next = n;
  }
}

int d_remove_at(d_list *l, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    return -1;
  }

  d_node *curr = get_at(l, idx);
  if (curr != NULL) {
    return remove_node(l, curr);
  }

  return -1;
}

int d_remove(d_list *l, int val) {
  if (l->head == NULL) {
    return -1;
  }

  if (l->head->val == val) {
    return remove_node(l, l->head);
  }

  d_node *prev = l->head;
  d_node *curr = l->head->next;

  while (curr != NULL) {
    if (curr->val == val) {
      return remove_node(l, curr);
    }

    prev = prev->next;
    curr = curr->next;
  }

  return -1;
}
