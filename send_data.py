import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
IP = "192.168.1.120"
PORT = 80

print ("Connecting ",s.connect((IP,PORT)))

msg = bytes("Hello","UTF-8")
print ("Sending: ",s.send(msg))
print ("msg sent");

data = s.recv(1024)
print ("Receive: ",data)
