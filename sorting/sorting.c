#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
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

Status_t intMerge(int dest[], 
                  int dest_len,
                  int array1[], 
                  int array1_len, 
                  int array2[], 
                  int array2_len) 
{
    int i = 0, j = 0, k = 0;

    while (j < array1_len && k < array2_len && i < dest_len) {
        if (array1[j] <= array2[k]) {
            dest[i] = array1[j];
            ++j;
        } else {
            dest[i] = array2[k];
            ++k;
        } 
        ++i;
    }

    while (j < array1_len && i < dest_len) {
        dest[i] = array1[j];
        ++j;
        ++i;
    }

    while (k < array2_len && i < dest_len) {
        dest[i] = array2[k];
        ++k;
        ++i;
    }

    return SUCCESS;
}

Status_t intMergeSort(int array[], int array_len) {
    
    if (array_len <= 1) {
        return SUCCESS;
    }

    int rc = SUCCESS;
    int mid = array_len / 2;
    
    // Sort left
    rc = intMergeSort(array, mid);
    if (rc) return rc;
    
    // Sort right
    rc = intMergeSort(&array[mid], array_len - mid);
    if (rc) return rc;

    // Merge
    int *dest = (int *) malloc(sizeof(int) * array_len);
    rc = intMerge(dest, array_len, array, mid, &array[mid], array_len - mid);
    if (rc) { 
        free(dest);
        return rc;
    }

    // Copy over sorted array from dest to array
    for (int i = 0; i < array_len; ++i) {
        array[i] = dest[i];
    }
    
    free(dest);
    
    return SUCCESS;
}
