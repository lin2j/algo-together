//
// Created by Kenny on 2022/8/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"

#include "priority_queue.h"

#define N 10

static int suite_init(void) {
        return 0; 
}

static int suite_clean(void)
{ 
        return 0; 
}

static int compare(const void *a, const void *b) 
{
        return *(int *)a - *(int *)b;
}

static void test_heap() 
{
        int arr[N] = {0};
        for (int i = 0; i < 10; i++)
                arr[i] = rand() % 100;

        PriorityQueue queue = new_priority_queue(0);
        for (int i = 0; i < N; i++)
                pq_offer(queue, arr[i]);
        qsort(arr, N, sizeof(int), compare);

        pq_print(queue);

        int e;
        for (int i = 0; i < N; i++) {
                pq_poll(queue, &e);
                CU_ASSERT_EQUAL(arr[i], e);
        }

        pq_free(queue);
}

int main(int argc, char **argv) 
{
        CU_pSuite pSuite = NULL;

        /* initialize the CUnit test registry */
        if (CUE_SUCCESS != CU_initialize_registry())
                return CU_get_error();

        /* add a suite to the registry */
        pSuite = CU_add_suite("suite_priority_queue", suite_init, suite_clean);
        if (NULL == pSuite) {
                CU_cleanup_registry();
                return CU_get_error();
        }
        /* add the tests to the suite */
        if ((NULL == CU_add_test(pSuite, "test_heap", test_heap))) {
                CU_cleanup_registry();
                return CU_get_error();
        }
        /* Run all tests using the CUnit Basic interface */
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();

        /* Clean up registry and return */
        CU_cleanup_registry();
        return CU_get_error();
}
