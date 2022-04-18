#include <stdio.h>
#include <stdlib.h>

#include "writer.h"
#include "message.h"

int main(int argc, char * argv[]) {
	int qid = accessQueue(FILE_PATH, ID_PROJ);
	if (qid < 0) {
		printf("error: main-accessQueue");
		return 1;
	}

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

	printf("enter eny number to exit:\n");
	int a; scanf("%d", &a);
	
	return 0;
}