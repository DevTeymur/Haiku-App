#ifndef __READER_H__
#define __READER_H__

#include <stdlib.h>
#include <pthread.h>
#include "message.h"

// func: reads one message from message queue
// args: a pointer to the value of priority
// return value: NULL
void *threadRead(void * arg);

// func: reads three message from the message queue by calling three thread
// args: priority of message
// return value: 0 in success, -1 in fail
int readHaiku(int category);

#endif // __READER_H__