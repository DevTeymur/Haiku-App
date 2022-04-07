#include "writer.h"

void *threadWrite(void * arg) {
  int category = *(int *)arg;
  if(writeHaiku(category)) {
    printf("error: threadWrite-writeHaiku\n");
  }
  pthread_exit(NULL);
}

int writeHaiku(int category) {

  int file = open(filePathes[category-1], O_RDONLY);
  if (file == -1) {
    printf("error: writeHaiku-file\n");
    return 1;
  }
  

  // FILE * file = fopen(filePathes[category-1], "r");
  // if (file == NULL) {
    
  // }

  int qid = accessQueue(FILE_PATH, ID_PROJ);
  if (qid == -1 || qid == -2) {
    printf("error: writeHaiku-qid\n");
    // fclose(file);
    return 2;
  }


  int index = 0;
  char haiku[127];
  while(read(file, &haiku[index], 1) != 0) {
    if (haiku[index] == '\n') {
      haiku[index] = '\0';
      printf("HAIKU: %s\n", haiku);
      writeMsg(qid, haiku, 2);
      index = 0;
      break;;
    }
    index++;
  }

  // while (fgets(haiku, 127, file) != NULL) {
    // printf("%s\n", haiku);
    // if(writeMsg(qid, haiku, category)){
      // printf("error: writeHaiku-writeResult\n");
      // fclose(file);
      // return 3;
    // }
  // }
  // fclose(file);
  return 0;
}

void startWriter() {
  int categories[2] = {1, 2};
  createQueue(FILE_PATH, ID_PROJ);
  pthread_t thread[2];
  if (pthread_create(&thread[0], NULL, threadWrite, (void *)&categories[0]) == -1) {
    // printf("error: startWriter-pthread_create-japanese\n");
  }
  // if (pthread_create(&thread[1], NULL, threadWrite, (void *)&categories[1]) == -1) {
    // printf("error: startWriter-pthread_create-western\n");
  // }

  if(pthread_join(thread[0], NULL) != 0) {
    // printf("error: startWriter-pthread_join-japanese\n");
  }
  // if(pthread_join(thread[1], NULL) != 0) {
    // printf("error: startWriter-pthread_join-japanese\n");
  // }
}