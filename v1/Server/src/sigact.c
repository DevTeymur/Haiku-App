#include "sigact.h"

void handleSignal(int sig) {
  printf(getCat(sig));
}

int initSignal(int sig, void * handler, int flags) {
  struct sigaction *sigact = (struct sigaction *)malloc(sizeof(struct sigaction));
  sigact->sa_handler = handler;
  sigact->sa_flags = flags;
  
  int result = sigaction(sig, sigact, NULL);
  if (result == -1) {
    printf("error: initSignal\n");
  }
  return result;
}