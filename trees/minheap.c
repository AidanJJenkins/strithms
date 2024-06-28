#include "../common/vec.h"
#include "tree.h"
#include <stdlib.h>

minheap *create_heap() {
  minheap *h = malloc(sizeof(minheap));
  vec *v = new_vec();
  h->length = 0;
  h->data = v;

  return h;
}

void heap_insert(minheap *h, int value) {
  push(h->data, value);
  h->length++;
  heapify_up(h, h->length - 1);
}

int heap_del(minheap *h) {
  if (h->length == 0) {
    return -1;
  }

  int out = h->data->items[0];
  h->length--;

  h->data->items[0] = h->data->items[h->length];
  heapify_down(h, 0);
  return out;
}

void heapify_down(minheap *h, int idx) {
  int lidx = left_child(idx);
  int ridx = right_child(idx);

  if (lidx >= h->length || idx >= h->length) {
    return;
  }

  int lv = h->data->items[lidx];
  int rv = h->data->items[ridx];
  int v = h->data->items[idx];

  if (lv > rv && v > rv) {
    h->data->items[idx] = rv;
    h->data->items[ridx] = v;
    heapify_down(h, ridx);
  } else if (rv > lv && v > lv) {
    h->data->items[idx] = lv;
    h->data->items[lidx] = v;
    heapify_down(h, lidx);
  }
}

void heapify_up(minheap *h, int idx) {
  if (idx == 0) {
    return;
  }

  int p = parent(idx);
  int pv = h->data->items[p];
  int v = h->data->items[idx];

  if (pv > v) {
    h->data->items[idx] = pv;
    h->data->items[p] = v;
    heapify_up(h, p);
  }
}

int parent(int idx) {
  int i = (idx - 1) / 2;
  return i;
}

int left_child(int idx) {
  int i = idx * 2 + 1;
  return i;
}

int right_child(int idx) {
  int i = idx * 2 + 2;
  return i;
}
