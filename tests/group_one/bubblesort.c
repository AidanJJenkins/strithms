#include "../../include/group_one/bubblesort.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

static void test() {
  int array_sort[MAX] = {0};

  for (int i = 0; i < MAX; i++) {
    array_sort[i] = rand() % 101;
  }

  bubblesort(array_sort, MAX);

  for (int i = 0; i < MAX - 1; i++) {
    assert(array_sort[i] <= array_sort[i + 1]);
  }
  printf("Bubblesort tests passed!\n");
}

int main() {
  test();
  return 0;
}
