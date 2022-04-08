#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "rvcPid.h"

int randomSignal();

int main(int argc, char * argv[])
{
	pid_t pid = rcvServerPid("../pid.fifo");
	if (pid < 0) {
		return 1;
	}
	printf("%d\n", pid);

	for (int i = 0; i < 100; i++) {
		kill(pid, randomSignal());
		sleep(1);
	}

	remove("../pid.fifo");
	return 0;
}

int randomSignal() {
  return rand() % 2 + 2;
}
