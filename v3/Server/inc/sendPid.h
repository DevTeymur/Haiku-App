#ifndef __SEND_PID__
#define __SEND_PID__

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FIFO_PATH "../pid.fifo"

int createFIFO(char *fifoPath);
int writeInFIFO(char *fifoPath, pid_t data);

#endif // __SEND_PID__