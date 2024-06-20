#include "../../include/group_one/stack.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void test_stack() {
  stack s;
  init_stack(&s);
  assert(&s != NULL);
  assert(s.count == 0);

  int *val1 = (int *)malloc(sizeof(int));
  *val1 = 5;
  push(&s, val1);
  assert(s.count == 1);
  assert(*(int *)s.head->val == 5);

  int *val2 = (int *)malloc(sizeof(int));
  *val2 = 9;
  push(&s, val2);

  int *val3 = (int *)malloc(sizeof(int));
  *val3 = 10;
  push(&s, val3);

  assert(s.count == 3);

  int *popped = (int *)pop(&s);
  assert(*popped == 10);
  free(popped);

  popped = (int *)pop(&s);
  assert(*popped == 9);
  free(popped);

  popped = (int *)pop(&s);
  assert(*popped == 5);
  free(popped);

  assert(s.count == 0);

  printf("Stack tests passed\n");
}
int main() {
  test_stack();
  return 0;
}
