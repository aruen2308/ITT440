#!/usr/bin/ruby
require 'socket'
server = TCPServer.open('192.168.174.130',37173)
loop{
	client = server.accept
	client.puts "Hello, there Server!"
	client.close
}
