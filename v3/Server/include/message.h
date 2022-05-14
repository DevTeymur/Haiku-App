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

// func: creates a message queue
// args: filePath and id_proj for ftok to generate key
// return value: id of queue in success, -1 if ftok fails, -2 if msgget fails
int createQueue(char * filePath, char id_proj);

// func: access an already existing message queue
// args: filePath and id_proj for ftok to generate key
// return value: id of queue in success,
//   -1 if ftok fails, -2 if msgget fails - queue doesn't exist
int accessQueue(char * filePath, char id_proj);

// func: remove an already existin message queue
// args: id of queue
// return value: 0 in success, -1 in fail
int removeQueue(int id);

// func: write a message into the message queue
// args: id of queue, string to be written into the qeueue, priority of message
// return value: 0 in success, -1 in fail
int writeMsg(int id, char data[], int mtype);

// func: read a message from the message queue
// args: id of queue, a buffer to write message in (not NULL), priority of message
// return value: 0 in success, -1 in fail
int readMsg(int id, Message * msg, int mtype);

#endif // __MESSAGE_H__