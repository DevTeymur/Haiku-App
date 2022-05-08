#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define FILE_PATH "/etc/passwd"
#define ID_PROJ 'F'

typedef struct _Message {
  long mtype;
  char data[127];
} Message;

int createQueue(char * filePath, char id_proj);
int accessQueue(char * filePath, char id_proj);
int removeQueue(int id);

int writeMsg(int id, char data[], int mtype);
int readMsg(int id, Message * msg, int mtype);

#endif // __MESSAGE_H__