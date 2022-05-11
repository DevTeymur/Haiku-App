#include "reader.h"

int numberOfHaikus[2] = {0, 0};

void checkQueueEntries(int category) {
  int index = category - 1;
  if (numberOfHaikus[index] < 3) {
    sendSignal(category + 1);
    if (category == 1)
      numberOfHaikus[index] = 6;
    else
      numberOfHaikus[index] = 9;
  }
}

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

  printf("%s\n", msg.data);
  pthread_exit(NULL);
}

int readHaiku(int category) {
  checkQueueEntries(category);
  numberOfHaikus[category - 1] -= 3;
  
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