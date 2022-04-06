#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <stdio.h>
#include <string.h>
#include <sys/msg.h>

typedef struct _Message {
  long mtype;
  char data[127];
} Message;

int createQueue(char *filePath, char id_proj);
int accessQueue(char *filePath, char id_proj);
int removeQueue(int id);

int writeMsg(int id, char *data);
int readMsg(int id, Message *msg, int mtype);

#endif // __MESSAGE_H__