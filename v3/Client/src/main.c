#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "sigact.h"

int main(int argc, char const *argv[]){

	int result = initSignal(SIGINT, &handleSignal, SA_RESTART);
	if (result < 0) {
		printf("error: main-initSignal-SIGINT\n");
		return 1;
	}
	
	result = initSignal(SIGQUIT, &handleSignal, SA_RESTART);
	if (result < 0) {
		printf("error: main-initSignal-SIGQUIT\n");
		return 1;
	}

	printf("Send signals to server with [Ctrl + C] for japanese or [Ctrl + \\] for western type.\nEnter any number to terminate\n");
	int a; scanf("%d", &a);
	
	return 0;
}
