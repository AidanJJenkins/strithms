#include "./linkedlist.h"
#include <assert.h>
#include <stdio.h>

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

void append(List *l, int val) {
  Node *n = create_node(val);
  l->count++;

  if (l->head == NULL) {
    l->head = n;
    l->tail = n;
    return;
  }

  l->tail->next = n;
  l->tail = n;
}

int r_pop(List *l) {
  Node *temp = l->head;
  int out = temp->val;

  l->head = temp->next;
  l->count--;

  free(temp);
  return out;
}

void revArray(int arr[], int size) {
  int reversed[size];
  for (int i = 0; i < size; i++) {
    reversed[size - i - 1] = arr[i];
  }

  for (int i = 0; i < size; i++) {
    arr[i] = reversed[i];
  }
}

void test_reverse() {
  List *l = init();

  int inputs[] = {2, 25, 42, 7, 21, 9, 68, 1009, 200};
  for (int i = 0; i < 9; i++) {
    append(l, inputs[i]);
  }

  reverse_i(l);
  revArray(inputs, 9);

  for (int i = 0; i < 9; i++) {
    int popped = r_pop(l);
    assert(popped == inputs[i]);
  }
}

void test_reverse_recursive() {
  List *l = init();

  int inputs[] = {2, 25, 42, 7, 21, 9, 68, 1009, 200};
  for (int i = 0; i < 9; i++) {
    append(l, inputs[i]);
  }

  reverse_r(l);
  revArray(inputs, 9);

  for (int i = 0; i < 9; i++) {
    int popped = r_pop(l);
    assert(popped == inputs[i]);
  }
}

int main() {
  test_reverse();
  test_reverse_recursive();
  printf("Reverse list tests passed\n");
  return 0;
}
