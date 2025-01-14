#include "calculator.h"
#include <CUnit/Basic.h>

void test_add() {
    CU_ASSERT(add(3, 5) == 8);
}

void test_subtract() {
    CU_ASSERT(subtract(10, 4) == 6);
}

void test_multiply() {
    CU_ASSERT(multiply(3, 5) == 15);
}

void test_divide() {
    CU_ASSERT(divide(10, 2) == 5.0);
    CU_ASSERT(divide(10, 0) == -1.0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Calculator Tests", 0, 0);

    CU_add_test(suite, "test_add", test_add);
    CU_add_test(suite, "test_subtract", test_subtract);
    CU_add_test(suite, "test_multiply", test_multiply);
    CU_add_test(suite, "test_divide", test_divide);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
