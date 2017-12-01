require "socket"
client = TCPSocket.open("192.168.222.129",2000)

puts "PLEASE ENTER YOUR MESSAGE HERE: "
message = gets.chomp

rhost = client.peeraddr.last
puts "#{rhost}"
client.write(message)
client.close