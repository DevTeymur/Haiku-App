#include "reader.h"

void *threadRead(void * arg) {
  int category = *(int *)arg;
  free(arg);
  
  int qid = accessQueue(FILE_PATH, ID_PROJ);
  if (qid < 0) {
    printf("error: threadRead-accessQueue\n");
    pthread_exit(NULL);
  }

  Message msg;
  int result = readMsg(qid, &msg, category);
  if (result < 0) {
    printf("error: threadRead-readMsg\n");
    pthread_exit(NULL);
  }

  printf("%s", msg.data);
  pthread_exit(NULL);
}

int readHaiku(int category) {
  for (int i = 0; i < 3; i++) {
    int * cat = (int *)malloc(sizeof(int));
    *cat = category; 
    pthread_t * thread = (pthread_t *) malloc(sizeof(pthread_t));
    if (pthread_create(thread, NULL, threadRead, (void *)cat) == -1) {
      printf("error: readHaiku-pthread_create(%d)\n", i);
      return -1;
    }
    pthread_detach(*thread);
  }
  return 0;
}