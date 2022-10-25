# -*- coding: utf-8 -*-
from base64 import decode
import socket

HOST = '192.168.10.251'
PORT = 10003

request = 'can you hear me?'
socket.setdefaulttimeout(5)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((HOST, PORT))

'''
TypeError: a bytes-like object is required, not 'str'
解决办法：
str→bytes：encode()方法。str通过encode()方法可以转换为bytes。
bytes→str: decode()方法。bytes通过decode()方法可以转换为str。
'''
s.send(b'\x55\x55')
#s.sendall(request.encode())


reply = s.recv(1024)
print(reply.hex())


# send 函数的参数和 recv 函数的返回值都是 bytes 类型

s.send(reply)

#print('reply is:', reply.decode())
s.close()