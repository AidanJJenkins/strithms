#include "search.h"

bool linear_search(int *arr, int target, int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return true;
    }
  }

  return false;
}
