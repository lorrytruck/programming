#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

double wtime()
{
struct timeval t;
gettimeofday(&t, NULL);
return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void PrintArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shell_sort(int arr[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void shell_sort_reverse(int arr[], int n) {
    int gap = n / 2;
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] < temp) { // заменяем > на <
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int left[mid], right[n - mid];
        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++) {
            right[i - mid] = arr[i];
        }
        merge_sort(left, mid);
        merge_sort(right, n - mid);
        merge(arr, left, mid, right, n - mid);
    }

}

void merge_reverse(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] > right[j]) { // заменяем < на >
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left_size) {
        arr[k++] = left[i++];
    }
    while (j < right_size) {
        arr[k++] = right[j++];
    }
}

void merge_sort_reverse(int arr[], int n) {
    if (n > 1) {
        int mid = n / 2;
        int left[mid], right[n - mid];
        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++) {
            right[i - mid] = arr[i];
        }
        merge_sort_reverse(left, mid);
        merge_sort_reverse(right, n - mid);
        merge_reverse(arr, left, mid, right, n - mid);
    }

}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Before shell sort: ");
    PrintArray(arr, n);

    //shell_sort_reverse(arr, n);
    double tshell = wtime();
    shell_sort(arr, n);
    tshell = wtime() - tshell;

    printf("After shell sort: ");
    PrintArray(arr, n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Before merge sort: ");
    PrintArray(arr, n);

    //merge_sort_reverse(arr, n);
    double tmerge = wtime();
    merge_sort(arr, n);
    tmerge = wtime() - tmerge;

    printf("After merge sort: ");
    PrintArray(arr, n);

    printf("Time sort: \n");
    printf("size  shell  merge\n");
    printf("%d %6lf %6lf \n", n, tshell, tmerge);

    free(arr);
    return 0;
}
