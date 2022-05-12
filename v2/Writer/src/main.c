#include <stdio.h>
#include <stdlib.h>

#include "writer.h"
#include "message.h"
#include "unitTest.h"

void cUnitTest();
void strCompare();

int main(int argc, char *argv[])
{

	// cUnitTest();

	int result = writeHaiku(1);
	if (result < 0)
	{
		printf("error: main-writeHaiku");
		return 2;
	}

	result = writeHaiku(2);
	if (result < 0)
	{
		printf("error: main-writeHaiku");
		return 3;
	}

	printf("Enter any number to exit\n");
	int b;
	scanf("%d", &b);

	return 0;
}

void strCompare()
{
	char *result1 = getHaikuFilePath(1);
	char *result2 = getHaikuFilePath(2);
	char *result3 = getHaikuFilePath(3);

	CU_ASSERT_STRING_EQUAL(result1, "res/japanese.txt");
	CU_ASSERT_STRING_EQUAL(result2, "res/western.txt");
	CU_ASSERT_PTR_EQUAL(result3, NULL);
}

void cUnitTest()
{
	if (CU_initialize_registry() != CUE_SUCCESS)
		printf("%s\n", "can't initialize test registry");

	CU_pSuite facSuite = CU_add_suite("strCompare", NULL, NULL);

	if (CU_get_error() != CUE_SUCCESS)
		printf("%s\n", "error_1");

	for (int i = 0; i < 100; i++)
	{
		CU_add_test(facSuite, "Signal Test", strCompare);
	}

	CU_basic_run_tests();
	CU_cleanup_registry();
}