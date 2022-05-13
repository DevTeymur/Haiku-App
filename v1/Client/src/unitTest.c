#include "unitTest.h"

void startUnitTests() {
	if (CU_initialize_registry() != CUE_SUCCESS)
		printf("%s\n", "can't initialize test registry");

	CU_pSuite randomSignalSuite = CU_add_suite("randomSignalTest", NULL, NULL);

	if (CU_get_error() != CUE_SUCCESS)
		printf("%s\n", "CUnit error");

	CU_add_test(randomSignalSuite, "Signal Test", randomSignalTest);

	CU_basic_run_tests();
	CU_cleanup_registry();
}

void randomSignalTest() {
	for (int i = 0; i < 128; i++) {
		int result = randomSignal();
		CU_ASSERT(result == 2 || result == 3);
	}
}
