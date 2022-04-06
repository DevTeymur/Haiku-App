#include "client.h"

int randSig() {
  int sig = rand() % 2 + 2;
  return sig;
}


void startClient() {

  for (int i = 0; i < 10; i++) {
    printf("%d ", randSig());
  }

  printf("Hello world");
}