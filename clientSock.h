#ifndef CLIENTSOCK_H
#define CLIENTSOCK_H
#include <iostream>
#include <future>
#include <functional>

#include <errno.h>
#include <string.h>

#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/signal.h>


using namespace std;

class clientSock {
  public:
    clientSock(string host, unsigned int port);
    clientSock();
    clientSock(int sock);
    ~clientSock();

    bool hasError();
    int connect(string host, unsigned int port);
    int disconnect();

    int write(string mesg);
    string read();
    string readAll();

    string host;
    unsigned int port;
    bool connected;

  protected:

  private:
    int enable_keepalive(int sock);

    static const unsigned int buffSize = 1000;
    int sockfd;//establish connection to ID distribution server
    struct sockaddr_in servaddr;
    char recv[buffSize];
    struct hostent* server;
};

#endif // CLIENTSOCK_H
