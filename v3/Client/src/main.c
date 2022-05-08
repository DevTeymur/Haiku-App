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

	// int input = 0;
	// while (1) {
	// 	printf("Enter a category to print haikus (1 - japanese, 2 - western, 0 - exit\n-> ");
	// 	scanf("%d", &input);
	// 	if (input == 0) break;
	// 	readHaiku(input);
	// }

	readHaiku(1);
	readHaiku(1);
	readHaiku(1);
	readHaiku(1);
	readHaiku(1);
	readHaiku(1);
	readHaiku(1);
	readHaiku(0);
	readHaiku(0);
	readHaiku(0);
	readHaiku(0);
	readHaiku(0);
	readHaiku(0);
	readHaiku(0);
	readHaiku(0);

	removeQueue(qid);
	printf("yes");

	return 0;
}