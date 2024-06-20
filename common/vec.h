#ifndef VEC_H
#define VEC_H
#include <stddef.h>

typedef struct {
  int *items;
  size_t count;
  size_t capacity;
} vec;

vec *new_vec();
void resize_vec(vec *arr);
void push(vec *arr, int item);
int pop(vec *arr);
int get_at(vec *arr, int idx);
void del_at(vec *arr, int idx);
void del_vec(vec *arr);

#endif
