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
    
    int array[ARRAY_LEN] = { 0, 1, 2, 3, 4, 0, 1, 2, 3, 4 };
    int sorted_array[ARRAY_LEN] = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4};

    Status_t rc = sorter(array, ARRAY_LEN);

    TEST_ASSERT_EQUAL_INT(SUCCESS, rc);
    TEST_ASSERT_EQUAL_INT_ARRAY(sorted_array, array, ARRAY_LEN);
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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_intBubbleSort_doSortSorted);
    RUN_TEST(test_intBubbleSort_doSortReverseSorted);
    RUN_TEST(test_intBubbleSort_doSortEmpty);
    RUN_TEST(test_intBubbleSort_doSortLen1);
    RUN_TEST(test_intBubbleSort_doSortPartial);
    RUN_TEST(test_intBubbleSort_doSortEvenLength);
    RUN_TEST(test_intBubbleSort_doSortOddLength);
    RUN_TEST(test_intBubbleSort_doSortAllSameNumber);
    return UNITY_END();
}

