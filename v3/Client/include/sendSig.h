#ifndef __SEND_SIG_H__
#define __SEND_SIG_H__

#include <signal.h>

#include "rvcPid.h"

// func: sends signal to server
// args: signal to be sent
// return value: none
void sendSignal(int signal);

#endif // __SEND_SIG_H__