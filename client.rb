require 'socket'

hostname ='192.168.174.130'
port=37173

s=TCPSocket.open(hostname, port)

while line =s.gets
	puts line.chomp
end
s.close

