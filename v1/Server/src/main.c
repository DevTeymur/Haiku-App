#include <stdio.h>
#include <stdlib.h>

#include "sendPid.h"
#include "sigact.h"

#define FIFO_PATH "../pid.fifo"

int main(int argc, char * argv[]) {
	createFIFO(FIFO_PATH);
	printf("start client to proceed\n");
	writeInFIFO(FIFO_PATH, getpid());

	initSignal(SIGINT, &handleSignal, SA_RESTART);
	initSignal(SIGQUIT, &handleSignal, SA_RESTART);

	printf("nice!\nenter any number to exit\n");
	int a;
	scanf("%d", &a);
	return 0;
}