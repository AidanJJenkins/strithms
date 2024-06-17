#include "../../include/group_one/bubblesort.h"

#include <stdbool.h>

void bubblesort(int *arr, int size) {
  bool sorted = false;

  while (!sorted) {
    sorted = true;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;

        sorted = false;
      }
    }
  }
}
