#include <stdio.h>
#include <stdlib.h>

#include "sendPid.h"
#include "sigact.h"

#define FIFO_PATH "../pid.fifo"

int main(int argc, char * argv[]) {
	int result = createFIFO(FIFO_PATH);
	if (result < 0) {
    printf("error: main-createFIFO\n");
		return 1;
	}

	printf("start client to proceed\n");

	result = writeInFIFO(FIFO_PATH, getpid());
	if (result < 0) {
    printf("error: main-writeInFIFO\n");
		return 2;
	}

	result = initSignal(SIGINT, &handleSignal, SA_RESTART);
	if (result < 0) {
    printf("error: main-initSignal-SIGINT\n");
		return 3;
	}
	result = initSignal(SIGQUIT, &handleSignal, SA_RESTART);
	if (result < 0) {
    printf("error: main-initSignal-SIGQUIT\n");
		return 4;
	}

	printf("Enter any number to exit:\n");
	int a; scanf("%d", &a);
	remove(FIFO_PATH);
	return 0;
}