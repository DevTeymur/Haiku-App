#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "rvcPid.h"

int randomSignal();

int main(int argc, char * argv[]) {
	srand(getpid());

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

int randomSignal() {
  return rand() % 2 + 2;
}
