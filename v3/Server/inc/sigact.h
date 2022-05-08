#ifndef __SIGACT_H__
#define __SIGACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
// #include <bits/sigaction.h>

#include "writer.h"

void handleSignal(int sig);
int initSignal(int sig, void * handler, int flags);

#endif // __SIGACT_H__