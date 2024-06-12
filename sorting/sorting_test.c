#include "unity.h"
#include "sorting.h"

typedef Status_t (*SortingFunction_t) (int array[], int array_length);

void setUp(void) {};
void tearDown(void) {};

static void sortSortedTest(SortingFunction_t sorter) {
    const int ARRAY_LEN = 5;

    int array[ARRAY_LEN] = {1, 2, 3, 4, 5};
    int sorted_array[ARRAY_LEN] = {1, 2, 3, 4, 5};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

static void sortReverseSortedTest(SortingFunction_t sorter) {
    const int ARRAY_LEN = 5;

    int array[ARRAY_LEN] = {5, 4, 3, 2, 1};
    int sorted_array[ARRAY_LEN] = {1, 2, 3, 4, 5};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

static void sortEmpty(SortingFunction_t sorter) {
    const int ARRAY_LEN = 0;

    int array[ARRAY_LEN] = { };

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT(sizeof(array), 0);
}

static void sortLen1(SortingFunction_t sorter) {
    const int ARRAY_LEN = 1;

    int array[ARRAY_LEN] = {5};
    int sorted_array[ARRAY_LEN] =  {5};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

static void sortPartial(SortingFunction_t sorter) {
    const int ARRAY_LEN = 10;

    int array[ARRAY_LEN] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int partially_sorted_array[ARRAY_LEN] = {6, 7, 8, 9, 10, 5, 4, 3, 2, 1};
    
    Status_t rc = sorter(array, ARRAY_LEN / 2);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(partially_sorted_array, array, ARRAY_LEN);
}

static void sortEvenLength(SortingFunction_t sorter) {
    const int ARRAY_LEN = 10;

    int array[ARRAY_LEN] = {0, 3, 6, 9, 2, 5, 8, 1, 4, 7};
    int sorted_array[ARRAY_LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

static void sortOddLength(SortingFunction_t sorter) {
    const int ARRAY_LEN = 9;

    int array[ARRAY_LEN] = {0, 3, 6, 2, 5, 8, 1, 4, 7};
    int sorted_array[ARRAY_LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

static void sortAllSameNumber(SortingFunction_t sorter) {
    const int ARRAY_LEN = 10;

    int array[ARRAY_LEN] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int sorted_array[ARRAY_LEN] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

static void sortSomeDuplicates(SortingFunction_t sorter) {
    const int ARRAY_LEN = 10;
    
    int array[ARRAY_LEN] = {0, 1, 2, 3, 4, 0, 1, 2, 3, 4};
    int sorted_array[ARRAY_LEN] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
}

void test_intMerge_doMergeSameLen(void) {
    int comparison[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int array1[5] = {1, 3, 5, 7, 9};
    int array2[5] = {0, 2, 4, 6, 8};
    int dest[10];
    
    Status_t rc = intMerge(dest, 10, array1, 5, array2, 5);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(comparison, dest, 10);
}

void test_intBubbleSort_doSortSorted(void) {
    sortSortedTest(intBubbleSort);
}

void test_intBubbleSort_doSortReverseSorted(void) {
    sortReverseSortedTest(intBubbleSort); 
}

void test_intBubbleSort_doSortEmpty(void) {
    sortEmpty(intBubbleSort);
} 

void test_intBubbleSort_doSortLen1(void) {
    sortLen1(intBubbleSort);
}

void test_intBubbleSort_doSortPartial(void) {
    sortPartial(intBubbleSort);
}

void test_intBubbleSort_doSortEvenLength(void) {
    sortEvenLength(intBubbleSort);
}

void test_intBubbleSort_doSortOddLength(void) {
    sortOddLength(intBubbleSort);
}

void test_intBubbleSort_doSortAllSameNumber(void) {
    sortAllSameNumber(intBubbleSort);
}

void test_intBubbleSort_doSortSomeDuplicates(void) {
    sortSomeDuplicates(intBubbleSort);
}

void test_intSelectionSort_doSortSorted(void) {
    sortSortedTest(intSelectionSort);
}

void test_intSelectionSort_doSortReverseSorted(void) {
    sortReverseSortedTest(intSelectionSort); 
}

void test_intSelectionSort_doSortEmpty(void) {
    sortEmpty(intSelectionSort);
} 

void test_intSelectionSort_doSortLen1(void) {
    sortLen1(intSelectionSort);
}

void test_intSelectionSort_doSortPartial(void) {
    sortPartial(intSelectionSort);
}

void test_intSelectionSort_doSortEvenLength(void) {
    sortEvenLength(intSelectionSort);
}

void test_intSelectionSort_doSortOddLength(void) {
    sortOddLength(intSelectionSort);
}

void test_intSelectionSort_doSortAllSameNumber(void) {
    sortAllSameNumber(intSelectionSort);
}

void test_intSelectionSort_doSortSomeDuplicates(void) {
    sortSomeDuplicates(intSelectionSort);
}

void test_intInsertionSort_doSortSorted(void) {
    sortSortedTest(intInsertionSort);
}

void test_intInsertionSort_doSortReverseSorted(void) {
    sortReverseSortedTest(intInsertionSort); 
}

void test_intInsertionSort_doSortEmpty(void) {
    sortEmpty(intInsertionSort);
} 

void test_intInsertionSort_doSortLen1(void) {
    sortLen1(intInsertionSort);
}

void test_intInsertionSort_doSortPartial(void) {
    sortPartial(intInsertionSort);
}

void test_intInsertionSort_doSortEvenLength(void) {
    sortEvenLength(intInsertionSort);
}

void test_intInsertionSort_doSortOddLength(void) {
    sortOddLength(intInsertionSort);
}

void test_intInsertionSort_doSortAllSameNumber(void) {
    sortAllSameNumber(intInsertionSort);
}

void test_intInsertionSort_doSortSomeDuplicates(void) {
    sortSomeDuplicates(intInsertionSort);
}

void test_intMergeSort_doSortSorted(void) {
    sortSortedTest(intMergeSort);
}

void test_intMergeSort_doSortReverseSorted(void) {
    sortReverseSortedTest(intMergeSort); 
}

void test_intMergeSort_doSortEmpty(void) {
    sortEmpty(intMergeSort);
} 

void test_intMergeSort_doSortLen1(void) {
    sortLen1(intMergeSort);
}

void test_intMergeSort_doSortPartial(void) {
    sortPartial(intMergeSort);
}

void test_intMergeSort_doSortEvenLength(void) {
    sortEvenLength(intMergeSort);
}

void test_intMergeSort_doSortOddLength(void) {
    sortOddLength(intMergeSort);
}

void test_intMergeSort_doSortAllSameNumber(void) {
    sortAllSameNumber(intMergeSort);
}

void test_intMergeSort_doSortSomeDuplicates(void) {
    sortSomeDuplicates(intMergeSort);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_intMerge_doMergeSameLen);

    /* ---- Bubble Sort Tests ---- */
    RUN_TEST(test_intBubbleSort_doSortSorted);
    RUN_TEST(test_intBubbleSort_doSortReverseSorted);
    RUN_TEST(test_intBubbleSort_doSortEmpty);
    RUN_TEST(test_intBubbleSort_doSortLen1);
    RUN_TEST(test_intBubbleSort_doSortPartial);
    RUN_TEST(test_intBubbleSort_doSortEvenLength);
    RUN_TEST(test_intBubbleSort_doSortOddLength);
    RUN_TEST(test_intBubbleSort_doSortAllSameNumber);
    RUN_TEST(test_intBubbleSort_doSortSomeDuplicates);

    /* ---- Selection Sort Tests ---- */
    RUN_TEST(test_intSelectionSort_doSortSorted);
    RUN_TEST(test_intSelectionSort_doSortReverseSorted);
    RUN_TEST(test_intSelectionSort_doSortEmpty);
    RUN_TEST(test_intSelectionSort_doSortLen1);
    RUN_TEST(test_intSelectionSort_doSortPartial);
    RUN_TEST(test_intSelectionSort_doSortEvenLength);
    RUN_TEST(test_intSelectionSort_doSortOddLength);
    RUN_TEST(test_intSelectionSort_doSortAllSameNumber);
    RUN_TEST(test_intSelectionSort_doSortSomeDuplicates);

    /* ---- Insertion Sort Tests ---- */
    RUN_TEST(test_intInsertionSort_doSortSorted);
    RUN_TEST(test_intInsertionSort_doSortReverseSorted);
    RUN_TEST(test_intInsertionSort_doSortEmpty);
    RUN_TEST(test_intInsertionSort_doSortLen1);
    RUN_TEST(test_intInsertionSort_doSortPartial);
    RUN_TEST(test_intInsertionSort_doSortEvenLength);
    RUN_TEST(test_intInsertionSort_doSortOddLength);
    RUN_TEST(test_intInsertionSort_doSortAllSameNumber);
    RUN_TEST(test_intInsertionSort_doSortSomeDuplicates);
    
    /* ---- Merge Sort Tests ---- */
    RUN_TEST(test_intMergeSort_doSortSorted);
    RUN_TEST(test_intMergeSort_doSortReverseSorted);
    RUN_TEST(test_intMergeSort_doSortEmpty);
    RUN_TEST(test_intMergeSort_doSortLen1);
    RUN_TEST(test_intMergeSort_doSortPartial);
    RUN_TEST(test_intMergeSort_doSortEvenLength);
    RUN_TEST(test_intMergeSort_doSortOddLength);
    RUN_TEST(test_intMergeSort_doSortAllSameNumber);
    RUN_TEST(test_intMergeSort_doSortSomeDuplicates);
    return UNITY_END();
}

