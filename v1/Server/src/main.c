#include <stdio.h>
#include <stdlib.h>

#include "sendPid.h"
#include "sigact.h"

int main(int argc, char * argv[]) {
	createFIFO("../pid.fifo");
	printf("start client to proceed\n");
	writeInFIFO("../pid.fifo", getpid());
	printf("nice!\nenter any number to exit\n");
	initSignal(SIGINT, &handleSignal, SA_RESTART);
	initSignal(SIGQUIT, &handleSignal, SA_RESTART);
	int a;
	scanf("%d", &a);
	return 0;
}