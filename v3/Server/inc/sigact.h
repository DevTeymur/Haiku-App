#ifndef __SIGACT_H__
#define __SIGACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "writer.h"

// func: handles incoming signal
// args: caught signal
// return value: none
void handleSignal(int sig);

// func: initialise a signal action
// args: signal to be caught, handler function, flags for action
// return value: 0 in success, -1 in fail
int initSignal(int sig, void * handler, int flags);

#endif // __SIGACT_H__