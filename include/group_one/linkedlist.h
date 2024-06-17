#ifndef LIST_H
#define LIST_H

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} Node;
typedef struct list {
  int count;
  struct node *head;
  struct node *tail;
} List;

List *init();
Node *create_node(int val);
void append(struct list *l, int val);
void prepend(struct list *l, int val);
int remove_val(struct list *l, int val);
void insert_at(struct list *l, int val, int idx);
int remove_at(struct list *l, int idx);
int get(struct list *l, int idx);
void print_list(struct list *l);

#endif
