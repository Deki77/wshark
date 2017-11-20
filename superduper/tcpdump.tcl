
tcpdump -i wlx98ded00ae211 -tt  | grep 1448  > tcpdump.txt &
sleep 2
./scpf1.tcl
pid=$(ps -e | pgrep tcpdump)
echo $pid 
sleep 5
kill $pid
#./tcpDump
