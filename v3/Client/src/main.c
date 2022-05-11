#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "rvcPid.h"

int main(int argc, char const *argv[]){

	pid_t serverPid = rcvServerPid(FIFO_PATH);

	char input = 0;
	printf("Enter a category to print haikus (j - japanese, w - western, 0 - exit\n-> ");
	while (1) {
		scanf("%c", &input);
		if (input == '0') break;
		else if (input == 'j')
			kill(serverPid, SIGINT);
		else if (input == 'w')
			kill(serverPid, SIGQUIT);
	}
	
	return 0;
}
