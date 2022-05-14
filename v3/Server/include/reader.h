#ifndef __READER_H__
#define __READER_H__

#include <stdlib.h>
#include <pthread.h>

#include "message.h"
#include "writer.h"

// func: checks the queue if it is out of message for a category
//   sends a signal to Server if it is out of messages in order to fill it
// args: the category of entries to be checked 
// return value: none
void checkQueueEntries(int category);

// func: reads one message from message queue
// args: a pointer to the value of priority
// return value: NULL
void *threadRead(void * arg);

// func: reads three message from the message queue by calling three thread
// args: priority of message
// return value: 0 in success, -1 in fail
int readHaiku(int category);

#endif // __READER_H__