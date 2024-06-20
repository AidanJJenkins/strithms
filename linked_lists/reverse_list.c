#include "../../include/group_one/linkedlist.h"
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

int pop(List *l) {
  Node *temp = l->head;
  int out = temp->val;

  l->head = temp->next;
  l->count--;

  free(temp);
  return out;
}

void print_list(List *l) {
  Node *current = l->head;
  while (current != NULL) {
    printf("curr: %d\n", current->val);
    current = current->next;
  }
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
    int popped = pop(l);
    assert(popped == inputs[i]);
  }
  printf("Reverse list tests passed\n");
}

int main() {
  test_reverse();
  return 0;
}
