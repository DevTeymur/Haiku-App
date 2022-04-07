#include "writer.h"

void *threadWrite(void * arg) {
  int category = *(int *)arg;
  if(writeHaiku(category)) {
    printf("error: threadWrite-writeHaiku\n");
  }
  pthread_exit(NULL);
}

// TODO: do this
int writeHaiku(int category) {
  FILE * file = fopen(filePathes[category-1], "r");
  if (file == NULL) {
    printf("error: writeHaiku-file\n");
    return 1;
  }

  int qid = accessQueue("Makefile", 'S');
  if (qid == -1 || qid == -2) {
    printf("error: writeHaiku-qid\n");
    return 2;
  }

  char haiku[127];
  // while(getline(&haiku, ))
  while (fgets(haiku, 127, file) != NULL) {
    puts("hello");
    if(writeMsg(qid, haiku, category)){
      printf("error: writeHaiku-writeResult\n");
      return 3;
    }
  }
  return 0;
}

void startWriter() {
  int categories[2] = {1, 2};
  createQueue("Makefile", 'S');
  pthread_t thread[2];
  if (pthread_create(&thread[0], NULL, threadWrite, (void *)&categories[0]) == -1) {
    printf("error: startWriter-pthread_create-japanese\n");
  }
  if (pthread_create(&thread[1], NULL, threadWrite, (void *)&categories[1]) == -1) {
    printf("error: startWriter-pthread_create-western\n");
  }

  if(pthread_join(thread[0], NULL) != 0) {
    printf("error: startWriter-pthread_join-japanese\n");
  }
  if(pthread_join(thread[1], NULL) != 0) {
    printf("error: startWriter-pthread_join-japanese\n");
  }
}