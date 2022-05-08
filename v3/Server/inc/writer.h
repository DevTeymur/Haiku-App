#ifndef __WRITER_H__
#define __WRITER_H__

#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "message.h"

static char * haikuFilePaths[2] = {
  "res/japanese.txt",
  "res/western.txt"
};

char * getHaikuFilePath(int category);
void *threadWrite(void * arg);
int writeHaiku(int category);

#endif // __WRITER_H__