#include "IntVector.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>

void copy_arr(int* arr, int* arr_c, size_t size) {
    for (int i = 0; i < size; i++) {
        arr_c[i] = arr[i];
    }
}


IntVector* int_vector_new(size_t capacity) {
    IntVector* darr = (IntVector*)malloc(sizeof(IntVector));
    darr->size = 0;
    darr->capacity = capacity;
    darr->data = (int*)calloc(capacity, sizeof(int));
    if (darr != NULL && darr->data != NULL) {
        return darr;
    }else {
        free(darr->data);
        free(darr);
        return NULL;
    }

}


IntVector *int_vector_copy(const IntVector* v) {
    IntVector* copy_v = int_vector_new(v->capacity);
    copy_v->size = v->size;
    copy_arr(v->data, copy_v->data, copy_v->size);
    return copy_v;
}


void int_vector_free(IntVector* v) {
    free(v->data);
    v->data = NULL;
    free(v);
    v = NULL;

}


int int_vector_get_item(const IntVector* v, size_t index) {
    return v->data[index];
}


void int_vector_set_item(IntVector* v, size_t index, int item) {
    v->data[index] = item;
}


size_t int_vector_get_size(const IntVector* v) {
    return v->size;
}


size_t int_vector_get_capacity(const IntVector* v) {
    return v->capacity;
}


int int_vector_push_back(IntVector *v, int item) {
  if (v->capacity > v->size) {
    v->data[v->size] = item;
    v->size++;
    return 0;
  } else {
    v->capacity = v->capacity * 2;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!(v->data)) {
      return -1;
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
  }
  if (errno)
    return -1;
}


void int_vector_pop_back(IntVector* v) {
    if (v->size > 0) {
        v->data[v->size] = 0;
        v->size--;
    }
}


int int_vector_shrink_to_fit(IntVector *v) {
  if (v->capacity == v->size) {
    return 0;
  } else {
    v->capacity = v->size;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!(v->data))
      return -1;
    return 0;
  }
  if (errno)
    return -1;
}

int int_vector_resize(IntVector* v, size_t new_size) {
if (new_size > v->size) {
    if (v->capacity < new_size) {
      v->capacity = new_size;
      v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    for (int i = new_size - (new_size - v->size); i < new_size; i++) {
      v->data[i] = 0;
    }
    v->size = new_size;
    return 0;
  } else if (new_size == v->size) {
    return 0;
  } else {
    printf("error : use int_vector_shrink_to_fit ");
    return -1;
  }
  if (errno)
    return -1;
}


int int_vector_reserve(IntVector* v, size_t new_capacity) {
  if (new_capacity > v->capacity) {
    v->capacity = new_capacity;
    v->data = realloc(v->data, v->capacity * sizeof(int));
    if (!(v->data))
      return -1;
    return 0;
  } else
    return 0;
  if (errno)
    return -1;
}
