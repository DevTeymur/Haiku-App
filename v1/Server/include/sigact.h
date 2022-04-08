#ifndef __SIGACT_H__
#define __SIGACT_H__

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define getCat(sig) sig == 2 ? "japanese\n" : "western\n"

void handleSignal(int sig);
int initSignal(int sig, void * handler, int flags);

#endif // __SIGACT_H__