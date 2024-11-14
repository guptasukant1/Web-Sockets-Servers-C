#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8181

int main() {
  int s, c;
  socklen_t addrlen;
  struct sockaddr_in srv, cli;
  addrlen = 0;

  memset(&srv, 0, sizeof(srv));
  memset(&cli, 0, sizeof(cli));

  s = socket(AF_INET, SOCK_STREAM, 0);

  if (s < 0) {
    printf("socket()\n");
    return -1;
  }

  srv.sin_family = AF_INET;
  srv.sin_addr.s_addr = 0;
  srv.sin_port = htons(PORT);

  if (bind(s, (struct sockaddr *)&srv, sizeof(srv))) {
    printf("bind()\n");
    return -1;
  }

  if (listen(s, 5)) {
    printf("listen()\n");
    return -1;
  }

  accept(s, (struct sockaddr *)&srv, &addrlen);
  c = acc
}
