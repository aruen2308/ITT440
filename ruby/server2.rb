require "socket"

while true
	server = TCPServer.open("192.168.132.130",4000)
	loadbalancer = server.accept
	puts loadbalancer.gets
	loadbalancer.close
	server.close
end