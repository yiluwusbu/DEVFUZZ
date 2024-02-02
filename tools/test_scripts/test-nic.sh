ifconfig eth0 hw ether 02:5d:6c:e8:8d:b2
ifconfig eth0 192.168.30.2 netmask 255.255.255.0
ip route add default via 192.168.30.1

ping 8.8.8.8 &
while [ true ]; do
  ifconfig eth0
  sleep 1
done
