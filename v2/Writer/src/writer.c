#include "writer.h"

void *threadWrite(void * arg) {
  int category = *(int *)arg;
  if(writeHaiku(category)) {
    printf("error: threadWrite\n");
  }
  pthread_exit(NULL);
}

int writeHaiku(int category) {
  FILE * file = fopen(filePathes(category), "r");
  if (file == NULL) {
    printf("error: writeHaiku-file\n");
    return 1;
  }

  int qid = accessQueue(FILE_PATH, ID_PROJ);
  if (qid == -1 || qid == -2) {
    printf("error: writeHaiku-qid\n");
    fclose(file);
    return 2;
  }

  char haiku[127];

  while (fgets(haiku, 127, file) != NULL) {
    if(writeMsg(qid, haiku, category)){
      printf("error: writeHaiku-writeResult\n");
      fclose(file);
      return 3;
    }
  }
  fclose(file);
  return 0;
}

void startWriter() {
  int category_j = 1, category_w = 2;
  createQueue(FILE_PATH, ID_PROJ);
  pthread_t thread_j, thread_w;
  if (pthread_create(&thread_j, NULL, threadWrite, (void *)&category_j) == -1) {
    printf("error: startWriter-pthread_create-japanese\n");
  }
  if (pthread_create(&thread_w, NULL, threadWrite, (void *)&category_w) == -1) {
    printf("error: startWriter-pthread_create-western\n");
  }

  if(pthread_join(thread_j, NULL) != 0) {
    printf("error: startWriter-pthread_join-japanese\n");
  }
  if(pthread_join(thread_w, NULL) != 0) {
    printf("error: startWriter-pthread_join-japanese\n");
  }
}