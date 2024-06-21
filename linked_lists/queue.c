#include "linkedlist.h"

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
    return NULL;
  }

  Node *temp = q->head;
  int out = temp->val;
  q->head = q->head->next;

  free(temp);
  return out;
}
