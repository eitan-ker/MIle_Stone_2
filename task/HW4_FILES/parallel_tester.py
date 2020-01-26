import socket
import time
import threading

IP = 'localhost'
PORT = 5600
SLEEP_TIME = 0.1
BUFFER_SIZE = 2048


def connect_clients():
    clients = []
    for i in range(10):
        client = socket.socket()
        clients.append(client)
    for i in range(10):
        clients[i].connect((IP, PORT))
        print ("client " + str(i + 1) + " connected to server")
    print ("")
    for i in range(10):
        t = threading.Thread(target=send_and_receive, args=(clients[i], i))
        t.start()


def send_and_receive(client, i):
    file_name = "Matrix" + str(i + 1) + ".txt"
    with open(file_name) as f:
        lines = f.readlines()
    for line in lines:
        client.send(line.encode('ASCII'))
        time.sleep(SLEEP_TIME)
   # print "client " + str(i + 1) + " sent to server"
    receive_message = client.recv(BUFFER_SIZE).decode('ASCII')
    print ("client " + str(i + 1) + " received:")
    print (receive_message)
    print ("")
    client.close()


connect_clients()
