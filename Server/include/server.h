#ifndef __SERVER_H__
#define __SERVER_H__

#include <stdio.h>
#include <signal.h>

#include "writer.h"

void handleSignal(int sig);
void startServer();

#endif // __SERVER_H__