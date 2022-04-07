#ifndef __WRITER_H__
#define __WRITER_H__

#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#include "message.h"

static char *filePathes[31] = {"res/japanese.txt", "res/western.txt"};

void *threadWrite(void * arg);
int writeHaiku(int category);
void startWriter();

#endif // __WRITER_H__