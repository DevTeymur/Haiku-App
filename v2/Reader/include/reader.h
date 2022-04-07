#ifndef __READER_H__
#define __READER_H__

#include "message.h"

void *threadRead(void * arg);
int readHaiku(int category);
void startReader();

#endif // __READER_H__