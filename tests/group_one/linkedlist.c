#include "../../include/group_one/linkedlist.h"
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void test_list() {
  List *l = init();

  int inputs[] = {2, 25, 42, 7, 21, 9, 68, 1009, 200};
  for (int i = 0; i < 9; i++) {
    append(l, inputs[i]);
    assert(l->tail->val == inputs[i]);
  }

  assert(l->count == 9);
  prepend(l, 48);
  assert(l->head->val == 48);
  assert(l->count == 10);

  int removed = remove_val(l, 21);
  assert(removed == 21);
  assert(l->count == 9);

  int gotten = get(l, 3);
  assert(gotten == 42);

  int gotten2 = get(l, 0);
  assert(gotten2 == 48);

  insert_at(l, 34, 3);
  int gotten3 = get(l, 3);
  assert(gotten3 == 34);

  int removed2 = remove_at(l, 4);
  assert(removed2 == 42);
  assert(l->count == 9);
  printf("Singly linked list tests passed\n");
}
int main() {
  test_list();
  return 0;
}
