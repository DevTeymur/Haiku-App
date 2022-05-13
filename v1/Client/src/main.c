#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "rvcPid.h"
#include "randSig.h"
#include "unitTest.h"

int main(int argc, char *argv[]) {
	srand(getpid());

	// startUnitTests();
	// return 0;

	pid_t pid = rcvServerPid(FIFO_PATH);
	if (pid < 0) {
		return 1;
	}

	for (int i = 0; i < 100; i++) {
		kill(pid, randomSignal());
		usleep(20000);
	}

	return 0;
}