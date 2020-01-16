import socket, sys
from socket import AF_INET, SOCK_STREAM

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
dest_ip = sys.argv[1]
dest_port = int(sys.argv[2])
while True:
 msg = "Hello1"
 s.connect((dest_ip, dest_port))
 s.send(msg.encode())
 data = s.recv(4096)
 s.close()
 data = data.decode()
 print(data)

