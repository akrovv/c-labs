#include "check_operations.h"

int main(void)
{
    int failed_tests = 0;
    SRunner *run_func = NULL;

    run_func = srunner_create(operations_suite());
    srunner_run_all(run_func, CK_VERBOSE);
    failed_tests += srunner_ntests_failed(run_func);
    srunner_free(run_func);
    run_func = NULL;    

    return (failed_tests == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
