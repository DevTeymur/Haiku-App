#include "reader.h"

int readHaiku(int msgId, int category) {
  Message msg;
  int result = readMsg(msgId, &msg, category);
  if (result) {
    printf("error: readHaiku");
    return 1;
  }
  return 0;
}