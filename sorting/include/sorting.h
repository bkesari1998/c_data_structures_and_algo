#pragma once

#include "status.h"

Status_t intBubbleSort(int array[], int array_length);

Status_t intSelectionSort(int array[], int array_len);

Status_t intInsertionSort(int array[], int array_len);

Status_t intMerge(int dest[], 
                  int dest_len,
                  int array1[], 
                  int array1_len, 
                  int array2[], 
                  int array2_len); 

Status_t intMergeSort(int array[], int array_len); 

