#include "vec.h"
#include <assert.h>
#include <stdio.h>

// havnt tested the delete at  yet
void test_vec() {
  int inputs[] = {21, 68, 45, 2, 100, 77};
  vec *v = new_vec();

  for (int i = 0; i < 6; i++) {
    push(v, inputs[i]);
  }

  for (int j = 0; j < (int)v->count; j++) {
    assert(inputs[j] == v->items[j]);
  }

  int popped = pop(v);
  assert(popped == 21);
  int popped2 = pop(v);
  assert(popped2 == 68);

  int gotten = v->items[1];
  assert(gotten == 2);

  del_vec(v);
  printf("Vec tests pass");
}

int main() {
  test_vec();
  return 0;
}
