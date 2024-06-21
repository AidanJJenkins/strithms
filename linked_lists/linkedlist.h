#ifndef LIST_H
#define LIST_H

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
void reverse_i(struct list *l);
void reverse_r(struct list *l);

// stack
typedef struct stack {
  int count;
  Node *head;
} stack;
stack *init_stack();
void push(stack *s, int data);
int pop(stack *s);
int peek(stack *s);

// queue
void enque(List *q, int data);
int deque(List *q);

// doubly linked list
typedef struct d_node {
  int val;
  struct d_node *next;
  struct d_node *prev;
} d_node;

typedef struct d_list {
  int count;
  d_node *head;
  d_node *tail;
} d_list;

d_list *init_d_list();
d_node *init_d_node(int val);
void d_append(d_list *l, int val);
void d_prepend(d_list *l, int val);
int remove_node(d_list *l, d_node *n);
int d_remove(d_list *l, int val);
int d_remove_at(d_list *l, int idx);
void d_insert_at(d_list *l, int val, int idx);
d_node *get_at(d_list *l, int idx);

#endif
