#include "sendPid.h"

int createFIFO(char *fifoPath) {
  int result = mkfifo(fifoPath, 0777);
  if (result == -1) {
    printf("error: createFIFO\n");
  }
  return result;
}

int writeInFIFO(char *fifoPath, pid_t data) {
  int fd = open(fifoPath, O_WRONLY | O_TRUNC);
  if (fd == -1) {
    printf("error: createFIFO-open\n");
    return -1;
  }
  size_t size = write(fd, &data, sizeof(data));
  if (size < 0) {
    printf("error: createFIFO-write\n");
    close(fd);
    return -2;
  }
  close(fd);
  return 0;
}