import socket
import sys
#COnst
PORT = 5000
SERV = sys.argv[1]
HEAD = 32
FORMAT='utf-8'
DISCONNECT_MESSAGE = 'Sjebal'
ADDR = (SERV,PORT)
ex = False

client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
if client.connect(ADDR):
    print("Con")

def start():
    while True:
        a=input()
        if a=="exit":

            send(a)
            break
        send(a)
def send(msg):
    message = msg.encode(FORMAT)
    msg_len=len(message)
    send_length = str(msg_len).encode(FORMAT)
    send_length +=b' ' * (HEAD-len(send_length))
    client.send(send_length)
    client.send(message)

start()
