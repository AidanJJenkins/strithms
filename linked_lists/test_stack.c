#include "./linkedlist.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void test_stack() {
  stack *s = init_stack();
  assert(s != NULL);
  assert(s->count == 0);

  push(s, 5);
  assert(s->count == 1);
  assert(s->head->val == 5);

  push(s, 9);

  push(s, 10);

  assert(s->count == 3);

  int popped = pop(s);
  assert(popped == 10);

  int popped1 = pop(s);
  assert(popped1 == 9);

  int popped2 = pop(s);
  assert(popped2 == 5);

  assert(s->count == 0);

  free(s);
  printf("Stack tests passed\n");
}

int main() {
  test_stack();
  return 0;
}
