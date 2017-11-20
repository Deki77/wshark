#!/usr/bin/expect

#netstat -s | grep -A 10 Tcp: > file1.txt
spawn scp root@172.31.1.1:/mnt/EWARM-CD-7803-12146.exe .
expect "root@172.31.1.1's password:"
send "bgw\r"
interact
#netstat -s | grep -A 10 Tcp: > file2.txt  


