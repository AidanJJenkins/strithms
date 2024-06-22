#include "./linkedlist.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

List *init() {
  List *l = malloc(sizeof(List));
  l->count = 0;
  l->head = NULL;
  l->tail = NULL;

  return l;
}

void test_queue() {
  struct list *l = init();
  assert(&l != NULL);
  assert(l->count == 0);

  enque(l, 5);
  assert(l->count == 1);
  assert(l->head->val == 5);

  enque(l, 10);
  assert(l->count == 2);
  assert(l->tail->val == 10);

  enque(l, 7);
  assert(l->count == 3);
  assert(l->tail->val == 7);

  enque(l, 42);
  assert(l->count == 4);
  assert(l->tail->val == 42);

  int popped = deque(l);
  assert(popped == 5);

  assert(l->count == 3);
  assert(l->head->val == 10);

  int popped2 = deque(l);
  assert(popped2 == 10);

  assert(l->count == 2);
  assert(l->head->val == 7);

  free(l);
  printf("Queue tests passed\n");
}
int main() {
  test_queue();
  return 0;
}
