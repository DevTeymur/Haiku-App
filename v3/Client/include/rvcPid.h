#ifndef __RCV_PID_H__
#define __RCV_PID_H__

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

// path for the fifo (aka named pipe)
#define FIFO_PATH "../pid.fifo"

// func: opens the fifo and read server pid
// args: path for fifo file
// return value: pid of server
pid_t rcvServerPid(char * fifoPath);

#endif // __RCV_PID_H__