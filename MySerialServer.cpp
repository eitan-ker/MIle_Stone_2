//
// Created by eizzker on 13/01/2020.
//


#include "MySerialServer.h"

void MySerialServer::open(int port, CLientHandler *c) {
  //  while (1) {
        thread ser(&MySerialServer::executeServer, this, port, c);
        ser.detach();
    //}
}

void MySerialServer::executeServer(int port, CLientHandler *c) {
    while (1) {
        //create socket
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd == -1) {
            //error
            std::cerr << "Could not create a socket" << std::endl;
            //   return -1;
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
            // return -2;
        }

        //making socket listen to the port
        if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
            std::cerr << "Error during listening command" << std::endl;
            //    return -3;
        } else {
            std::cout << "Server is now listening ..." << std::endl;
        }

        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address,
                                   (socklen_t *) &address);
        if (client_socket == -1) {
            std::cerr << "Error accepting client" << std::endl;
            //  return -4;
        }
        (*c).handleClient(client_socket);
    }
}


void MySerialServer::stop() {
    cout << "stop\n" << endl;
}

void MySerialServer::protocol() {
    cout << "protocol\n" << endl;
}

