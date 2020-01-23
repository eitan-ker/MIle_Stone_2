//
// Created by eizzker on 13/01/2020.
//

#include <thread>
#include "MyParallelServer.h"

void MyParallelServer::open(int port, CLientHandler<string,string,Point> *c) {
    //  while (1) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
    }

    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
    }
    //executeServer(c, address, socketfd);
    thread ser(&MyParallelServer::executeServer, this, c, address, socketfd);
    ser.detach();

}

void MyParallelServer::executeServer(CLientHandler<string,string,Point> *c, sockaddr_in address, int socketfd) {
    //create socket

    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        //    return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    // time out
    while (1) {
        //making socket listen to the port

        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);
        if (client_socket == -1) {
            std::cerr << "Error accepting client" << std::endl;
            //  return -4;
        }
        std::cout << "client is now connected" << std::endl;
        thread thr(&MyParallelServer::runThread, this, c, client_socket);
        thr.detach();
    }
}

void MyParallelServer::runThread(CLientHandler<string,string,Point> *c, int client_socket) {
    c->handleClient(client_socket);
}


void MyParallelServer::stop() {
    cout << "stop\n" << endl;
}
