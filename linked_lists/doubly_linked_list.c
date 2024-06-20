#include "../../include/group_one/doubly_linked_list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_doubly_list() {
  d_list *l = init_d_list();

  int inputs[] = {2, 25, 42, 7, 21, 9, 68, 1009, 200};
  for (int i = 0; i < 9; i++) {
    d_append(l, inputs[i]);
    assert(l->tail->val == inputs[i]);
  }

  assert(l->count == 9);
  d_prepend(l, 48);
  assert(l->head->val == 48);
  assert(l->count == 10);

  int r = remove_node(l, l->head);
  assert(r == 48);

  d_node *gotten = get_at(l, 3);
  assert(gotten->val == 7);

  int removed = d_remove_at(l, 3);
  assert(removed == 7);

  d_insert_at(l, 69, l->count);
  d_insert_at(l, 12, 3);
  assert(l->tail->val == 69);

  d_node *g2 = get_at(l, 3);
  assert(g2->val == 12);

  d_insert_at(l, 21, 0);
  assert(l->head->val == 21);
  // print_d_list(l);
  // int removed = remove_val(l, 21);
  // assert(removed == 21);
  // assert(l->count == 9);
  //
  // int gotten = get(l, 3);
  // assert(gotten == 42);
  //
  // int gotten2 = get(l, 0);
  // assert(gotten2 == 48);
  //
  // insert_at(l, 34, 3);
  // int gotten3 = get(l, 3);
  // assert(gotten3 == 34);
  //
  // int removed2 = remove_at(l, 4);
  // assert(removed2 == 42);
  // assert(l->count == 9);
  free(l);
  printf("Doubly linked list tests passed\n");
}
int main() {
  test_doubly_list();
  return 0;
}
