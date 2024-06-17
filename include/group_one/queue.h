#ifndef QUEUE_H
#define QUEUE_H

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
  void *val;
  struct node *next;
};
struct list {
  int count;
  struct node *head;
  struct node *tail;
};

struct list *init();
struct node *create_node(void *val);
void enque(struct list *l, void *val);
void *deque(struct list *l);
void print_queue(struct list *l);

#endif
