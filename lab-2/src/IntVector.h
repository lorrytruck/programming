#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct IntVector{
    int* data;
    size_t size;
    size_t capacity;
}IntVector;

void copy_arr(int* arr, int* arr_c, size_t size);

IntVector* int_vector_new(size_t capacity);

IntVector *int_vector_copy(const IntVector* v);

void int_vector_free(IntVector* v);

int int_vector_get_item(const IntVector* v, size_t index);

void int_vector_set_item(IntVector* v, size_t index, int item);

size_t int_vector_get_size(const IntVector* v);

size_t int_vector_get_capacity(const IntVector* v);

int int_vector_push_back(IntVector* v, int item);

void int_vector_pop_back(IntVector* v);

int int_vector_shrink_to_fit(IntVector* v);

int int_vector_resize(IntVector* v, size_t new_size);

int int_vector_reserve(IntVector* v, size_t new_capacity);
