#ifndef __SEND_PID__
#define __SEND_PID__

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

// path for the fifo (aka named pipe)
#define FIFO_PATH "../pid.fifo"

// func: creates a fifo file
// args: path for fifo file
// return value: 0 in success, -1 in fail
int createFIFO(char *fifoPath);

// func: write pid in fifo
// args: path for fifo file, pid
// return value: 0 in success, -1 in fail of openning fifo, -2 in fail of writing into fifo
int writeInFIFO(char *fifoPath, pid_t data);

#endif // __SEND_PID__