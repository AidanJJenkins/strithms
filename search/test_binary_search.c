#include "search.h"
#include <assert.h>
#include <stdio.h>

void test_binary_search() {
  int arr[] = {2, 3, 4, 10, 40};

  assert(binary_search(arr, 10, 5) == true);
  assert(binary_search(arr, 2, 5) == true);
  assert(binary_search(arr, 40, 5) == true);
  assert(binary_search(arr, 5, 5) == false);
  assert(binary_search(arr, -1, 5) == false);
  assert(binary_search(arr, 100, 5) == false);

  printf("Binary search tests passed!\n");
}

int main() {
  test_binary_search();
  return 0;
}
