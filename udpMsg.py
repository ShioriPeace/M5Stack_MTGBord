from socket import socket, AF_INET, SOCK_DGRAM, sys

PORT = 2222
ADDRESS = "192.168.68.120" 

s = socket(AF_INET, SOCK_DGRAM)

print(sys.version)

while True:
    msg = input("> ")
    s.sendto(msg.encode(), (ADDRESS, PORT))
s.close()