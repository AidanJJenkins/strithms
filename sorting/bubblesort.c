#include "sorting.h"
#include <stdbool.h>

void bubblesort(int *arr, int size) {
  bool s = true;
  while (s) {
    s = false;
    for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        s = true;
      }
    }
    size--;
  }
}
