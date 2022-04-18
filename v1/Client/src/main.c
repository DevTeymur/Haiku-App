#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <CUnit/CUnit.h>

#include "rvcPid.h"

#define FIFO_PATH "../pid.fifo"

int randomSignal();

void test_fac_0(void) {
  CU_ASSERT_EQUAL(randomSignal(), 1);
}

int main(int argc, char * argv[]) {
	pid_t pid = rcvServerPid(FIFO_PATH);
	if (pid < 0) {
		return 1;
	}
	
	printf("%d\n", pid);

	for (int i = 0; i < 100; i++) {
		kill(pid, randomSignal());
		sleep(1);
	}

	return 0;
}

int randomSignal() {
  return rand() % 2 + 2;
}
