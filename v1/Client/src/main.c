#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "rvcPid.h"

#define FIFO_PATH "../pid.fifo"

int randomSignal();

int main(int argc, char * argv[]) {
	pid_t pid = rcvServerPid(FIFO_PATH);
	if (pid < 0) {
		return 1;
	}
	remove(FIFO_PATH);
	
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
