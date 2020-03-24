'''

Author: Frederick Driver
Date & time:March 24th 1AM



Mission:
three machines
hardcoded ip's
each allow 1 input from command line
waits for other two
everyone prints all three numbers


'''

ip1 = "hardcoded server ip here"
ip2 = "first hardcoded client ip here"
ip3 = "second hardcoded client ip here"

import time, socket, sys
print('Setup Server...')
time.sleep(1)
#Get the hostname, IP Address from socket and set Port
soc = socket.socket()
port = 1234
soc.bind((ip1, port))
print(ip1, '({})'.format(ip1))
num = input('Enter number: ')
soc.listen(2) #Try to locate using socket
print('waiting for connections...')

connection, addr = soc.accept()
c1num = connection.recv(1024)

print("Received connection from ", addr[0], "(", addr[1], ")\n")
print('Connection Established. Connected From: {}, ({})'.format(addr[0], addr[0]))


connection2, addr2 = soc.accept()
c2num = connection2.recv(1024)

print("Received connection from ", addr2[0], "(", addr[1], ")\n")
print('Connection Established. Connected From: {}, ({})'.format(addr2[0], addr2[0]))

#get a connection from client side

c1num = c1num.decode()
c2num = c2num.decode()

#print the numbers, order not preserved
print(c1num + " "+c2num+" "+num)
connection.send((num +" "+ c2num).encode())
connection2.send((num +" "+ c1num).encode())
