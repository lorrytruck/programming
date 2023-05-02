#include "IntVector.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


void print_array(int* arr, int n) {
	printf("elements of array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	IntVector* ex;
	ex = int_vector_new(10);
	ex->data[0] = 888;
	ex->size++;
	printf("first elevent of Vector ex = %d;\n", ex->data[0]);

	IntVector* ex_copy = int_vector_copy(ex);
	printf("first element of Vector ex_copy = %d; his size = %ld;\n", ex_copy->data[0], ex_copy->size);

	int_vector_push_back(ex, 123);
	int_vector_push_back(ex, 8);

	printf("first element of Vector ex = %d, second = %d, third = %d; his size %ld; his capacity = %ld;\n", int_vector_get_item(ex, 0), int_vector_get_item(ex, 1), int_vector_get_item(ex, 2), int_vector_get_size(ex), int_vector_get_capacity(ex));

	printf("second element of Vector ex = %d;\n", int_vector_get_item(ex, 1));

	int_vector_set_item(ex, 1, 666);

	printf("second element of Vector ex = %d;\n", int_vector_get_item(ex, 1));

	int_vector_pop_back(ex);

	printf("size of Vector = %ld; capacity of Vector ex = %ld;\n", int_vector_get_size(ex), int_vector_get_capacity(ex));

	int t = int_vector_shrink_to_fit(ex);

	printf("flag = %d; capacity of Vector ex = %ld;\n", t, int_vector_get_capacity(ex));

	print_array(ex->data, int_vector_get_size(ex));

	int y = int_vector_resize(ex, 8);

	printf("flag = %d; size of Vector = %ld; capacity of Vector ex = %ld;\n", y, int_vector_get_size(ex), int_vector_get_capacity(ex));

	print_array(ex->data, int_vector_get_size(ex));

	int x = int_vector_reserve(ex, 16);

	printf("flag = %d; size of Vector = %ld; capacity of Vector ex = %ld;\n", x, int_vector_get_size(ex), int_vector_get_capacity(ex));

	int_vector_free(ex_copy);
	int_vector_free(ex);
}
