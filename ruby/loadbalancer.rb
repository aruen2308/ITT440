require "socket"

loadbalancer = TCPServer.open("192.168.222.129",2000)

while true
	client = loadbalancer.accept

	rhost = clien.peeraddr.last
	puts "#{rhost} connect to load balancer"

	fromclient = client.gets
	puts "MESSAGE FROM CLIENT: #{fromclient}"

	if fromclient == "rich"
		sockettoserver1 = TCPSocket.open("192.168.132.129",3000)
		sockettoserver1.write(fromclient)
		sockettoserver1.close

	elsif fromclient == "poor"
		sockettoserver2 = TCPSocket.open("192.168.132.130",4000)
		sockettoserver2.write(fromclient)
		sockettoserver2.close

	else
		puts "OPSS! ERROR!"

	end
end