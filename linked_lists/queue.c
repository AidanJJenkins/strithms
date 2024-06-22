#include "linkedlist.h"
#include <stdlib.h>

Node *create_node(int val) {
  Node *n = malloc(sizeof(Node));
  n->val = val;
  n->next = NULL;

  return n;
}

void enque(List *q, int data) {
  Node *n = create_node(data);
  q->count++;

  if (q->head == NULL) {
    q->head = n;
    q->tail = n;
    return;
  }

  q->tail->next = n;
  q->tail = n;
}

int deque(List *q) {
  if (q->head == NULL) {
    return -1;
  }

  Node *temp = q->head;
  int out = temp->val;
  q->head = q->head->next;
  q->count--;

  free(temp);
  return out;
}
