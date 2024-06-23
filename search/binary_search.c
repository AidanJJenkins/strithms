#include "search.h"

bool binary_search(int haystack[], int needle, int size) {
  int lo = 0;
  int hi = size;

  while (lo <= hi) {
    int m = lo + (hi - lo) / 2;

    if (haystack[m] == needle) {
      return true;
    } else if (haystack[m] > needle) {
      hi = m - 1;
    } else {
      lo = m + 1;
    }
  }

  return false;
}
