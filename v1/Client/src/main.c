#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "rvcPid.h"
#include "unitTest.h"

int randomSignal();
void randomSignalTest();
void cUnitTest();

int main(int argc, char *argv[])
{
	srand(getpid());

	// cUnitTest();

	pid_t pid = rcvServerPid(FIFO_PATH);
	if (pid < 0)
	{
		return 1;
	}

	for (int i = 0; i < 100; i++)
	{
		kill(pid, randomSignal());
		usleep(20000);
	}

	return 0;
}

int randomSignal()
{
	return rand() % 2 + 2;
}

void randomSignalTest()
{
	int result = randomSignal();

	CU_ASSERT(result == 2 || result == 3);
}

void cUnitTest()
{
	if (CU_initialize_registry() != CUE_SUCCESS)
		printf("%s\n", "can't initialize test registry");

	CU_pSuite facSuite = CU_add_suite("randomSignalTest", NULL, NULL);

	if (CU_get_error() != CUE_SUCCESS)
		printf("%s\n", "error_1");

	for (int i = 0; i < 100; i++)
	{
		CU_add_test(facSuite, "Signal Test", randomSignalTest);
	}

	CU_basic_run_tests();
	CU_cleanup_registry();
}