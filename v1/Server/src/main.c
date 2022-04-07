#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <bits/sigaction.h>

// #define filePathes(cat) cat == 1 ? "res/japanese.txt" : "res/western.txt"

void handleSignal(int sig);

int main(int argc, char * argv[])
{
	struct sigaction sig;

	return 0;
}