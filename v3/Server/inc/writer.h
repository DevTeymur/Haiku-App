#ifndef __WRITER_H__
#define __WRITER_H__

#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "message.h"

// matrix (array of strings) for storing paths of haikus
static char * haikuFilePaths[2] = {
  "res/japanese.txt",
  "res/western.txt"
};

// func: getting path of haiku file
// args: category of haiku
// return value: path of haiku file (string)
char * getHaikuFilePath(int category);

// func: writes haikus into the message queue read from haiku file
// args: a pointer to the value of priority
// return value: NULL
void *threadWrite(void * arg);

// func: writes all haikus from a file into the message queue by calling a thread
// args: priority of message
// return value: 0 in success, -1 in fail
int writeHaiku(int category);

#endif // __WRITER_H__