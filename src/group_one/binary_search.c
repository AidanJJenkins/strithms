#include "../../include/group_one/binary_search.h"
#include <stdbool.h>

bool binary_search(int haystack[], int needle, int size) {
  int left = 0;
  int right = size - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (haystack[mid] == needle) {
      return true;
    }
    if (haystack[mid] < needle) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return false;
}
