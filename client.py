import time, socket, sys

ip1 = "hard coded server ip here"
ip2 = "hard coded client ip here"

print('Client Server...')
time.sleep(1)
#Get the hostname, IP Address from socket and set Port
soc = socket.socket()
shost = socket.gethostname()
ip = socket.gethostbyname(shost)
#get information to connect with the server
print(shost, '({})'.format(ip))
server_host = ip1
num = input('Enter Client\'s num: ')
port = 1234
print('Trying to connect to the server: {}, ({})'.format(server_host, port))
time.sleep(1)
soc.connect((server_host, port))
print("Connected...\n")
soc.send(num.encode())
nums = soc.recv(1024)
nums = nums.decode()
print(nums+" "+num)
