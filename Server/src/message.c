#include "message.h"

int createQueue(char *filePath, char id_proj) {
  key_t key = ftok(filePath, id_proj);
  if (key == -1) {
    printf("error: createQueue-key\n");
    return -1;
  }
  int id = msgget(key, IPC_CREAT | 0666);
  if (id == -1) {
    printf("error: createQueue-id\n");
    return -2;
  }
  return id;
}

int accessQueue(char *filePath, char id_proj) {
  key_t key = ftok(filePath, id_proj);
  if (key == -1) {
    printf("error: accessQueue-key\n");
    return -1;
  }
  int id = msgget(key, 0);
  if (id == -1) {
    printf("error: accessQueue-id\n");
    return -2;
  }
  return id;  
}

int removeQueue(int id) {
  int result = msgctl(id, IPC_RMID, NULL);
  if (result == -1) {
    printf("error: removeQueue\n");
    return 1;
  }
  return 0;
}

int writeMsg(int id, char data[], int mtype) {
  Message msg;
  msg.mtype = mtype;
  strcpy(msg.data, data);
  if (msg.data[strlen(msg.data)-1] == '\n')
    msg.data[strlen(msg.data)-1] = '\0';

  int result = msgsnd(id, &msg, sizeof(char) * strlen(msg.data) + 1, 0);
  if (result == -1) {
    printf("error: writeMsg\n");
    return 1;
  }
  return 0;
}

int readMsg(int id, Message *msg, int mtype) {
  int result = msgrcv(id, msg, sizeof(*msg) - sizeof(msg->mtype), mtype, 0);
  if (result == -1) {
    printf("error: readMsg\n");
    return 1;
  }
  return 0;
}
