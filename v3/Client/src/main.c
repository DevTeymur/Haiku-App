#include <stdio.h>
#include <stdlib.h>

#include "reader.h"

int main(int argc, char * argv[])
{
	int qid = createQueue(FILE_PATH, ID_PROJ);
	if (qid < 0) {
		printf("error: main-createQueue");
		return 1;
	}

	int input = 0;
	printf("Enter a category to print haikus (1 - japanese, 2 - western, 0 - exit\n-> ");
	while (1) {
		scanf("%d", &input);
		if (input == 0) break;
		readHaiku(input);
	}

	removeQueue(qid);

	return 0;
}