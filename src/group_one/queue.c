#include "../../include/group_one/queue.h"
#include <stdlib.h>

struct list *init() {
  struct list *l = (struct list *)malloc(sizeof(struct list));

  l->count = 0;
  l->head = NULL;
  l->tail = NULL;

  return l;
}

struct node *create_node(void *val) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->val = val;
  n->next = NULL;

  return n;
}

void enque(struct list *l, void *val) {
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

void *deque(struct list *l) {
  if (l->head == NULL) {
    return NULL;
  }

  struct node *temp = l->head;
  void *out = temp->val;
  l->head = l->head->next;

  if (l->head == NULL) {
    l->tail = NULL;
  }

  free(temp);
  l->count--;
  return out;
}

void print_queue(struct list *queue) {
  struct node *current = queue->head;
  while (current != NULL) {
    printf("curr: %d\n", *(int *)current->val);
    current = current->next;
  }
}
