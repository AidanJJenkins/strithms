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

int get(struct list *l, int idx) {
  if (l->head == NULL || idx > l->count || idx < 0) {
    return -1;
  }

  Node *curr = l->head;
  for (int i = 0; i < idx; i++) {
    curr = curr->next;
  }

  return curr->val;
}

void insert_at(struct list *l, int val, int idx) {
  if (l->head == NULL || idx > l->count || idx < 0) {
    return;
  } else if (idx <= 0) {
    prepend(l, val);
  } else if (idx == l->count) {
    append(l, val);
  }

  Node *prev = l->head;
  Node *curr = l->head->next;
  int i = 1;

  while (curr != NULL) {
    if (i == idx) {
      Node *n = create_node(val);
      prev->next = n;
      n->next = curr;
      l->count++;
    }
    i++;
    prev = curr;
    curr = curr->next;
  }
}

int remove_at(struct list *l, int idx) {
  if (l->head == NULL || idx > l->count || idx < 0) {
    return -1;
  }

  if (idx == 0) {
    Node *temp = l->head;
    l->head = l->head->next;
    l->count--;
    int out = temp->val;
    free(temp);
    return out;
  }

  Node *prev = l->head;
  Node *curr = l->head->next;
  int i = 1;
  while (curr != NULL) {
    if (i == idx) {
      Node *temp = curr;
      prev->next = curr->next;
      int out = temp->val;
      l->count--;
      free(temp);
      return out;
    }
    i++;
    prev = curr;
    curr = curr->next;
  }

  return -1;
}

void print_list(struct list *l) {
  Node *current = l->head;
  while (current != NULL) {
    printf("curr: %d\n", current->val);
    current = current->next;
  }
}
