#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "client.h"

int main(int argc, char * argv[])
{
	srand(getpid());
	startClient();
	return 0;
}