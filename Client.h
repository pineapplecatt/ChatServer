#ifndef CHATROOM_CLIENT_H
#define CHATROOM_CLIENT_H

#include <sys/types.h>
#include <string>
#include "Common.h"

using namespace std;

// client class...
class Client {
   public:
    // constructor
    Client();
    // connect the server
    void Connect();
    // close the client
    void Close();
    // start the client
    void Start();

   private:
    // the server socket
    int sock;
    // the process id
    pid_t pid;
    // the epoll_create return
    int epfd;
    // create pipe, fd[0] the father read, fd[1] the child write
    // fd参数返回两个文件描述符,fd[0]指向管道的读端,fd[1]指向管道的写端。fd[1]的输出是fd[0]的输入。
    int pipe_fd[2];
    // if the client work
    bool isClientWork;
    // chat message buffer
    char message[BUF_SZIE];
    // server ip + port
    sockaddr_in serverAddr;
};

#endif  // CHATROOM_CLINET_H