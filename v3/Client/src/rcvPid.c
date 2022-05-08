#include "rvcPid.h"

pid_t rcvServerPid(char * fifoPath) {
  int fd = open(fifoPath, O_RDONLY);
  if (fd == -1) {
    printf("error: rcvServerPid-open\n");
    return -1;
  }

  pid_t serverPid;

  size_t size = read(fd, &serverPid, sizeof(serverPid));
  if (size < 0) {
    close(fd);

    printf("error: rcvServerPid-read\n");
    return -2;
  }
  
  close(fd);
  return serverPid;
}