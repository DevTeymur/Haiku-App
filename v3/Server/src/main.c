#include <stdio.h>
#include <stdlib.h>

#include "sigact.h"
#include "sendPid.h"

int main(int argc, char * argv[])
{
	int result = initSignal(SIGINT, &handleSignal, SA_RESTART);
	if (result < 0) {
		printf("error: main-initSignal-SIGINT\n");
		return 1;
	}
	
	result = initSignal(SIGQUIT, &handleSignal, SA_RESTART);
	if (result < 0) {
		printf("error: main-initSignal-SIGQUIT\n");
		return 2;
	}

	result = createFIFO(FIFO_PATH);
	if (result < 0) {
		printf("error: main-createFIFO\n");
		return 3;
	}

	result = writeInFIFO(FIFO_PATH, getpid());
	if (result < 0) {
		printf("error: main-writeInFIFO\n");
		return 4;
	}

	printf("Server started\n  enter any number to exit: ");
	int a; scanf("%d", &a);
	remove(FIFO_PATH);
	return 0;
}