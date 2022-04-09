#ifndef __READER_H__
#define __READER_H__

#include <stdlib.h>
#include <pthread.h>
#include "message.h"

void *threadRead(void * arg);
int readHaiku(int category);

#endif // __READER_H__