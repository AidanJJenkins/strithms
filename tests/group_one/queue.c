#include "../../include/group_one/queue.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void test_queue() {
  struct list *l = init();
  assert(&l != NULL);
  assert(l->count == 0);

  int *val1 = (int *)malloc(sizeof(int));
  *val1 = 5;
  enque(l, val1);
  assert(l->count == 1);
  assert(*(int *)l->head->val == 5);

  int *val2 = (int *)malloc(sizeof(int));
  *val2 = 10;
  enque(l, val2);
  assert(l->count == 2);
  assert(*(int *)l->tail->val == 10);

  int *val3 = (int *)malloc(sizeof(int));
  *val3 = 7;
  enque(l, val3);
  assert(l->count == 3);
  assert(*(int *)l->tail->val == 7);

  int *val4 = (int *)malloc(sizeof(int));
  *val4 = 42;
  enque(l, val4);
  assert(l->count == 4);
  assert(*(int *)l->tail->val == 42);

  int *popped = (int *)deque(l);
  assert(*popped == 5);
  free(popped);

  assert(l->count == 3);
  assert(*(int *)l->head->val == 10);

  int *popped2 = (int *)deque(l);
  assert(*popped2 == 10);
  free(popped2);

  assert(l->count == 2);
  assert(*(int *)l->head->val == 7);

  printf("Queue tests passed\n");
}
int main() {
  test_queue();
  return 0;
}
