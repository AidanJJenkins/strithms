#include "../../include/group_one/quick_sort.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

static void test_quick_sort() {
  int arr[MAX] = {0};

  for (int i = 0; i < MAX; i++) {
    arr[i] = rand() % 101;
  }

  int n = sizeof(arr) / sizeof(arr[0]);

  // Function call
  quickSort(arr, 0, n - 1);

  for (int i = 0; i < MAX - 1; i++) {
    assert(arr[i] <= arr[i + 1]);
  }
  printf("Quick sort tests passed!\n");
}

int main() {
  test_quick_sort();
  return 0;
}
