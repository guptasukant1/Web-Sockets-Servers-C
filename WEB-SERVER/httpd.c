#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define LOCALADDR "127.0.0.1"

// Returns 0 on error else socket fd
int srv_init(int portNo) {
  int s;

  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    printf("socket failed to connect\n");
    return -1;
  }
  return s;
}

int main(int argc, char *argv[]) {
  int s;

  char *port;
  if (argc < 2) {
    fprintf(stderr, "Usage: %s < listening port>\n", argv[0]);
    return -1;
  } else {
    port = argv[1];
  }

  s = srv_init(stoi(port));
}
