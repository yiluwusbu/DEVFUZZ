name=$1
while [ true ];
do
  rmmod $name
  sleep 2
  modprobe $name
  lspci -vvv | grep $name
done
