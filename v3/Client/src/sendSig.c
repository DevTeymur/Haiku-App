#include "sendSig.h"

pid_t serverPid = 0;

void sendSignal(int signal) {
  if (serverPid == 0) {
    serverPid = rcvServerPid(FIFO_PATH);
  }
  kill(serverPid, signal);
}