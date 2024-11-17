# Repo for Web Sockets and Web Servers using C/C++

## To create a web socket and server using C

Create a socket.c file that is a socket connection to a static URL (www.google.se) and with a static PORT (80). This creates a connection between the local device's port and the website. The socket is initialised via a socket file descriptor and a socket internet address structure (sockaddr_in). This allows to set the connection parameters including the PORT, the internet family (AF_INET) and the IP address to connect to. The socket is initialised with the internet family/domain (AF_INET for IPv4 protocol), type of the communication to be carried out (SOCK_STREAM for sequenced 2-way byte streams and are full duplex byte streams), the protocol to be used with the socket. Once the connection is established the data can be sent and received using read and write.


