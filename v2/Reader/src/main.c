#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "reader.h"

int main(int argc, char * argv[]) {
	int qid = createQueue(FILE_PATH, ID_PROJ);
	if (qid < 0) {
		printf("error: main-createQueue");
		return 1;
	}

	printf("Start writer to proceed\n\n");

	int result = readHaiku(1);
	if (result < 0) {
		printf("error: main-readHaiku");
		return 2;
	}

	result = readHaiku(2);
	if (result < 0) {
		printf("error: main-readHaiku");
		return 3;
	}

	printf("Enter any number to exit\n");
	int b; scanf("%d", &b);

	result = removeQueue(qid);
	if (result < 0) {
		printf("error: main-removeQueue\n");
		return 4;
	}

	return 0;
}