#include "sorting.h"
#include <stdio.h>
#include <stdbool.h>

static Status_t swap(int *element_1, int *element_2) {
    int tmp = *element_1;
    *element_1 = *element_2;
    *element_2 = tmp;

    return SUCCESS;
}

Status_t intBubbleSort(int array[], int array_len) {
    bool is_sorted = true;

    do {
        is_sorted = true;
        // Loop over elements
        for (int i = 0; i < (array_len - 1); ++i) {
            // Swap elements if left element is greater than right element
            if (array[i] > array[i + 1]) {
                is_sorted = false;
                Status_t rc = swap(&array[i], &array[i + 1]);
                if (rc == FAILURE) return rc;
            }
        }
    } while ( !is_sorted );

    return SUCCESS;
}

Status_t intSelectionSort(int array[], int array_len) {
    
    for (int i = 0; i < array_len; ++i) {
        int min_idx = i;
        for (int j = (i + 1); j < array_len; ++j) {
            if (array[min_idx] > array[j]) {
                min_idx = j;
            }
        }
        Status_t rc = swap(&array[i], &array[min_idx]);
        if (rc == FAILURE) return rc;
    }

    return SUCCESS;
}

Status_t intInsertionSort(int array[], int array_len) {
    
    for (int i = 0; i < array_len; ++i) {
        int key = array[i];

        int j = i - 1;
        while ( j >= 0 && array[j] > key ) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }

    return SUCCESS;
}
