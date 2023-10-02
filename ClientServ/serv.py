import socket
import threading
#CONST VALUES
PORT = 5000
SERV = socket.gethostbyname(socket.gethostname())
ADDR = (SERV,PORT)
HEAD = 32
FORMAT='utf-8'
DISCONNECT_MESSAGE = 'exit'
#FUNC

server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)



server.bind(ADDR)
def handle_client(conn,addr):
    print(f'New con {addr}\n')
    connected=True
    while connected:
        msg_length = conn.recv(HEAD).decode(FORMAT)
        if msg_length:
            msg_length = int(msg_length)
            msg = conn.recv(msg_length).decode(FORMAT)
            if msg == DISCONNECT_MESSAGE:
                connected=False
            print(f'{addr} {msg}')

    conn.close()
def start():
    server.listen()
    print(f"{SERV} is listening on port {PORT}")
    while True:
        conn,addr = server.accept()
        thread = threading.Thread(target=handle_client,args=(conn,addr))
        thread.start()
        print(f'Conns {threading.active_count()-1}')

#START

print("START")
start()
