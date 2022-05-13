#include "unitTest.h"

void startUnitTests() {
	if (CU_initialize_registry() != CUE_SUCCESS)
		printf("%s\n", "can't initialize test registry");

	CU_pSuite haikuPathSuite = CU_add_suite("getHaikuPathSuite", NULL, NULL);
	CU_pSuite msgSuite = CU_add_suite("messageSuite", NULL, NULL);

	if (CU_get_error() != CUE_SUCCESS)
		printf("%s\n", "CUnit error");

	CU_add_test(haikuPathSuite, "getHaikuPathSuite", haikuPathTest);
	CU_add_test(msgSuite, "messageSuite", messageQueueTest);

	CU_basic_run_tests();
	CU_cleanup_registry();
}

void haikuPathTest() {
	for (int i = 0; i < 32; i++) {
		char *result1 = getHaikuFilePath(1);
		char *result2 = getHaikuFilePath(2);
		char *result3 = getHaikuFilePath(3);

		CU_ASSERT_STRING_EQUAL(result1, "res/japanese.txt");
		CU_ASSERT_STRING_EQUAL(result2, "res/western.txt");
		CU_ASSERT_PTR_EQUAL(result3, NULL);
	}
}

void messageQueueTest() {
	int qid = createQueue(FILE_PATH, ID_PROJ);

	char messages[32][10] = {
		"test-1",
		"test-2",
		"test-3",
		"test-4",
		"test-5",
		"test-6",
		"test-7",
		"test-8",
		"test-9",
		"test-11",
		"test-12",
		"test-13",
		"test-14",
		"test-15",
		"test-16",
		"test-17",
		"test-18",
		"test-19",
		"test-21",
		"test-22",
		"test-23",
		"test-24",
		"test-25",
		"test-26",
		"test-27",
		"test-28",
		"test-29",
		"test-30",
		"test-31",
		"test-32"
	};

	for (int i = 0; i < 32; i++) {
		writeMsg(qid, messages[i], 1);
		Message msg;
		readMsg(qid, &msg, 1);

		CU_ASSERT_STRING_EQUAL(msg.data, messages[i]);
	}

	removeQueue(qid);
}
