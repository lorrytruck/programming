#include "IntVector.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

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


int int_vector_push_back(IntVector* v, int item) {
    int flag = -1;
    if (v->size == v->capacity) {
        int mass[v->size];
        copy_arr(v->data, mass, v->size);
        free(v->data);
        v->data = (int*)calloc(v->size*2, sizeof(int));
        copy_arr(mass, v->data, v->size);
        v->data[v->size] = item;
        v->capacity = v->size*2;
        flag = 0;
    }else {
        v->data[v->size] = item;
        flag = 0;
    }
    v->size++;
    return flag;
}


void int_vector_pop_back(IntVector* v) {
    if (v->size > 0) {
        v->data[v->size] = 0;
        v->size--;
    }
}


int int_vector_shrink_to_fit(IntVector* v) {
    int flag = -1;
    if (v->size != v->capacity) {
        v->capacity = v->size;
        int mass[v->size];
        copy_arr(v->data, mass, v->size);
        free(v->data);
        v->data = (int*)calloc(v->size, sizeof(int));
        copy_arr(mass, v->data, v->size);
        flag = 0;
    }
    return flag;
}


int int_vector_resize(IntVector* v, size_t new_size) {
    int flag = -1;
    if (new_size > v->size) {
        if (new_size >= v->capacity) {
            int mass[v->size];
            copy_arr(v->data, mass, v->size);
            free(v->data);
            v->data = (int*)calloc(new_size, sizeof(int));
            copy_arr(mass, v->data, v->size);
            v->size = new_size;
            v->capacity = new_size;
            flag = 0;
        }else {
            for (int i = v->size; i < new_size; i++) {
                v->data[i] = 0;
            }
            v->size = new_size;
            flag = 0;
        }
    }else {
        v->size = new_size;
        int_vector_shrink_to_fit(v);
        flag = 0;
    }
    return flag;
}


int int_vector_reserve(IntVector* v, size_t new_capacity) {
    int flag = -1;
    if (new_capacity > v->capacity) {
        int mass[v->size];
        copy_arr(v->data, mass, v->size);
        free(v->data);
        v->data = (int*)calloc(new_capacity, sizeof(int));
        copy_arr(mass, v->data, v->size);
        v->capacity = new_capacity;
        flag = 0;
    }
    return flag;
}
