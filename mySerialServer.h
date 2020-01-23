//
// Created by shira on 13.1.2020.
//

#ifndef EX4__MYSERIALSERVER_H_
#define EX4__MYSERIALSERVER_H_

#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
using namespace server_side;


//#include "MyTestClientHandler.h"
//#include <vector>
//#include <thread>

class mySerialServer : public Server {
 private:
  int socketfd; //, client_socket;
  sockaddr_in address;  //in means IP4////////////////////////////////////////
  bool active;
  //vector<thread> threadVector;
 public:
  //ctor
  mySerialServer() {
    this->active = true;
    //put 0s in address
    bzero((char *) &this->address, sizeof(this->address));
  }

  virtual int open(int port, ClientHandler c);
  virtual int stop() {
    this->active = true;
    close(this->socketfd);//closing the listening socket
  }
 // void readWriteProtocol(int client_socket);
 // int accept(int socketfd);
  void * handleThreadFunc(void* args);

};

#endif //EX4__MYSERIALSERVER_H_
