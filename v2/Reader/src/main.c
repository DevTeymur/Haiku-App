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

	printf("Start writer to proceed\n");
	int result = readHaiku(1);
	if (result < 0) {
		printf("error: main-readHaiku");
		return 2;
	}

	printf("enter eny number to exit:\n");
	int a; scanf("%d", &a);

	result = removeQueue(qid);
	if (result < 0) {
		printf("error: main-writeHaiku");
		return 3;
	}

	return 0;
}