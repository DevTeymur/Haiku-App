#include "reader.h"

void *threadRead(void * arg) {
  int category = *(int *)arg;
  
}

int readHaiku(int category) {
  int qid = accessQueue(FILE_PATH, ID_PROJ);
  Message msg;
  readMsg(qid, &msg, category);
  printf("%s", msg.data);
}

void startReader() {
  int qid = accessQueue(FILE_PATH, ID_PROJ);
  printf("REMOVED");
  removeQueue(qid);
}