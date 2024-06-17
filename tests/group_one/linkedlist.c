#include "../../include/group_one/linkedlist.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void test_list() {
  struct list *l = init();
  assert(&l != NULL);
  assert(l->count == 0);

  int val1 = 5;
  append(l, val1);
  assert(l->count == 1);
  assert(l->head->val == 5);

  int val2 = 10;
  append(l, val2);
  assert(l->count == 2);
  assert(l->tail->val == 10);

  int val3 = 21;
  prepend(l, val3);
  assert(l->count == 3);
  assert(l->head->val == 21);

  int removed = remove_val(l, 10);
  assert(removed == 10);
  assert(l->count == 2);

  // print_list(l);
  printf("Singly linked list tests passed\n");
}
int main() {
  test_list();
  return 0;
}
