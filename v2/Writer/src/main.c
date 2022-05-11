#include <stdio.h>
#include <stdlib.h>

#include "writer.h"
#include "message.h"

int main(int argc, char * argv[]) {
	
	int result = writeHaiku(1);
	if (result < 0) {
		printf("error: main-writeHaiku");
		return 2;
	}

	result = writeHaiku(2);
	if (result < 0) {
		printf("error: main-writeHaiku");
		return 3;
	}

	printf("Enter any number to exit\n");
	int b; scanf("%d", &b);

	return 0;
}