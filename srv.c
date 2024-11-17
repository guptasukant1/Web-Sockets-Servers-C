#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8181 // Server listens on this port

int main() {
  int s, c;
  socklen_t addrlen;           // For Accept function.
  struct sockaddr_in srv, cli; // Structure for server and client addresses
  char buf[1024];              // Buffer to store data sent by client
  char *data;                  // Pointer to data sent to client

  memset(&srv, 0, sizeof(srv));
  memset(&cli, 0, sizeof(cli));

  // Creating the TCP(SOCK_STREAM) server socket using IPv4(AF_INET) and listens for incoming connections
  s = socket(AF_INET, SOCK_STREAM, 0);
  if (s < 0) {
    printf("socket()\n");
    return -1;
  }

  // Setting the server connetion parameters
  srv.sin_family = AF_INET; // Sets the address family to IPv4
  srv.sin_addr.s_addr = htonl(INADDR_ANY);
  // Allows binding to all network interfaces
  srv.sin_port = htons(PORT); // Converts host byte order to network byte order

  // Binding the parameters of the server
  if (bind(s, (struct sockaddr *)&srv, sizeof(srv))) { // Binds the srv to s.
    printf("bind()\n");
    close(s);
    return -1;
  }

  // Server listens to the client socket connection upto 5 connection requests
  if (listen(s, 5)) {
    printf("listen()\n");
    close(s);
    return -1;
  }
  printf("Listening on 0.0.0.0:%d\n", PORT);

  addrlen = sizeof(cli);
  // Server accepts a client connection (we do not need to manually initialize the cli struct as it gets its IP and PORT via accept() based on client connection)
  c = accept(s, (struct sockaddr *)&cli, &addrlen);
  // Listening fd, address struct where cli info is stored, sizeof add struct. The cli struct populated automatically and not manually. As a client connects,
  // accept creates a new socket conn, sets IP and PORT for cli

  if (c < 0) {
    printf("accept()\n");
    close(s);
    return -1;
  }

  char client_ip[INET_ADDRSTRLEN];
  // inet_tops converts binary to decimal, ntohs: network byte order to host byte order
  inet_ntop(AF_INET, &(cli.sin_addr), client_ip, INET_ADDRSTRLEN); // Obtains the client cli struct info
  printf("Client connected from %s:%d\n", client_ip, ntohs(cli.sin_port));

  read(c, buf, 1023); // Reads data from client and is a blocking call
  data = "Hello There JDotW!\n";
  write(c, data, strlen(data)); // Sends response to client

  close(c);
  close(s);
}
