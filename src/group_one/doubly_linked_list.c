#include "../../include/group_one/doubly_linked_list.h"
#include <stdlib.h>

d_list *init_d_list() {
  d_list *list = malloc(sizeof(d_list));
  list->count = 0;
  list->head = NULL;
  list->tail = NULL;

  return list;
}

d_node *init_d_node(int val) {
  d_node *node = malloc(sizeof(d_node));
  node->val = val;
  node->next = NULL;
  node->prev = NULL;

  return node;
}

void d_prepend(d_list *l, int val) {
  d_node *new = init_d_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = new;
    l->tail = new;
    return;
  }

  new->next = l->head;
  l->head->prev = new;
  l->head = new;
}

void d_append(d_list *l, int val) {
  d_node *new = init_d_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = new;
    l->tail = new;
    return;
  }

  l->tail->next = new;
  new->prev = l->tail;
  l->tail = new;
}

int remove_node(d_list *l, d_node *n) {
  if (n == NULL || l == NULL) {
    printf("list or node is null");
    return -1;
  }

  l->count--;
  if (l->count == 0) {
    l->head = NULL;
    l->tail = NULL;
  }

  if (n->prev != NULL) {
    n->prev->next = n->next;
  }

  if (n->next != NULL) {
    n->next->prev = n->prev;
  }

  if (n == l->head) {
    l->head = n->next;
  }

  if (n == l->tail) {
    l->tail = n->prev;
  }

  int out = n->val;
  free(n);
  return out;
}

d_node *get_at(d_list *l, int idx) {
  if (l->head == NULL || idx > l->count || idx < 0) {
    return NULL;
  }

  d_node *curr = l->head;
  for (int i = 0; i < idx; i++) {
    curr = curr->next;
  }

  return curr;
}

int d_remove_at(d_list *l, int idx) {
  if (l->head == NULL || idx < 0 || idx > l->count) {
    return -1;
  }

  d_node *n = get_at(l, idx);
  if (n != NULL) {
    int out = remove_node(l, n);
    return out;
  }
  return -1;
}

void d_insert_at(d_list *l, int val, int idx) {
  if (l->head == NULL || idx > l->count) {
    return;
  } else if (idx <= 0) {
    d_prepend(l, val);
    return;
  } else if (idx == l->count) {
    d_append(l, val);
    return;
  }

  l->count++;
  d_node *found = get_at(l, idx);
  d_node *new = init_d_node(val);

  new->next = found;
  new->prev = found->prev;
  found->prev = new;

  if (new->prev != NULL) {
    new->prev->next = new;
  }
}

void print_d_list(d_list *l) {
  d_node *current = l->head;
  while (current != NULL) {
    printf("curr: %d\n", current->val);
    current = current->next;
  }
}
