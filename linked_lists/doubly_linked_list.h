#ifndef DLIST_H
#define DLIST_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct d_node {
  int val;
  struct d_node *next;
  struct d_node *prev;
} d_node;

typedef struct d_list {
  int count;
  struct d_node *head;
  struct d_node *tail;
} d_list;

d_list *init_d_list();
d_node *init_d_node(int val);
void d_append(d_list *l, int val);
void d_prepend(d_list *l, int val);
void print_d_list(d_list *l);
int remove_node(d_list *l, d_node *n);
d_node *get_at(d_list *l, int idx);
int d_remove_at(d_list *l, int idx);
void d_insert_at(d_list *l, int val, int idx);
// int remove_val(struct list *l, int val);

#endif
