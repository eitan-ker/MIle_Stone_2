//
// Created by eizzker on 25/01/2020.
//

#include <thread>
#include "MyParallelServer.h"
#include "RunThread.h"

void *socketThread(RunThread &run);

void MyParallelServer::open(int port, CLientHandler<string, string, Point> *c) {
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
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        //    return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }

    auto t = [](int socketfd, sockaddr_storage storage, pthread_t temp_thr[60],
                CLientHandler<string, string, Point> *c, MyParallelServer *ifRun) {
        int i;
        while (!ifRun->stopRunning) {
            i = 0;
            //Accept call creates a new socket for the incoming connection
            socklen_t addrSize = sizeof storage;
            int client_socket = accept(socketfd, (struct sockaddr *) &storage, &addrSize);
            // using lamda func to run handle client
            RunThread *run = new RunThread(c, client_socket);
            //so the main thread can entertain next request
            if (pthread_create(&temp_thr[i], NULL, reinterpret_cast<void *(*)(void *)>(socketThread),
                               run) != 0)
                printf("Failed to create thread\n");
            if (i >= 50) {
                i = 0;
                while (i < 50) {
                    pthread_join(temp_thr[i++], NULL);
                }
            }
        }
    };
    pthread_t thr[60];
    sockaddr_storage storage;
    std::thread thread_object(t, socketfd, storage, thr, c, this);
    thread_object.detach();
}

void MyParallelServer::stop() {
    this->stopRunning = true;
}

void *socketThread(RunThread &run) {
    run.getClientHandler()->handleClient(run.get_Client_Socket());
    printf("Exit socketThread \n");
    close(run.get_Client_Socket());
    pthread_exit(NULL);
}
