#include "sorting.h"
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

    return 0;
}
