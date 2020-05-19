import socket
import threading 

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
active_ports = []

def port_scan(ip,port,delay):
	s.settimeout(delay)
	try:
		s.socketconnect((ip,port))
		active_ports.append(port)
	except:
		pass

def scan(ip,delay):
	threads = []
	for i in range(1024):
		t = threading.Thread(target=port_scan,args=(ip,i,delay))
	for i in range(1024):
		t.start()
	for i in range(1024):
		t.join()
	for i in range(1024):
		port_scan(ip,i,delay)

def main():
	host_ip = input("Enter the IP Address of the host : ")
	print(f"The IP Address enetered is : {host_ip}")
	delay = int(input("Enter the required delay : "))
	scan(host_ip,delay)

if __name__ == "__main__":
	main()
