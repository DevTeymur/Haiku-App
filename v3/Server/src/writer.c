#include "writer.h"

char * getHaikuFilePath(int category) {
  if (category == 1) {
    return haikuFilePaths[0];
  }
  else if (category == 2) {
    return haikuFilePaths[1];
  }
  else return NULL;
}

void *threadWrite(void * arg) {
  int category = *(int *)arg;
  free(arg);

  char * filePath = getHaikuFilePath(category);
  if (filePath == NULL) {
    printf("error: threadWrite-getHaikuFilePath");
    pthread_exit(NULL);
  }

  FILE * file = fopen(filePath, "r");
  if (file == NULL) {
    printf("error: threadWrite-fopen\n");
    pthread_exit(NULL);
  }

  int qid = accessQueue(FILE_PATH, ID_PROJ);
  if (qid < 0) {
    printf("error: threadWrite-accessQueue\n");
    fclose(file);
    pthread_exit(NULL);
  }

  char haiku[127];

  while (fgets(haiku, 127, file) != NULL) {
    if(writeMsg(qid, haiku, category) < 0){
      printf("error: threadWrite-writeResult\n");
      fclose(file);
      pthread_exit(NULL);
    }
  }
  fclose(file);
  pthread_exit(NULL);
}

int writeHaiku(int category) {
  int * cat = (int *)malloc(sizeof(int));
  *cat = category; 
  pthread_t * thread = (pthread_t *) malloc(sizeof(pthread_t));
  if (pthread_create(thread, NULL, threadWrite, (void *)cat) == -1) {
    printf("error: writeHaiku-pthread_create\n");
    return -1;
  }
  pthread_detach(*thread);
  return 0;
}