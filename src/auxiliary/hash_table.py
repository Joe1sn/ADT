#coding=utf-8
#python3.8

from hashlib import sha1, sha256, md5
msg = b"hello world"
print(msg)
print("msg_sha1:",sha1(msg).hexdigest())
print("msg_sha256:",sha256(msg).hexdigest())
print("msg_md5:",md5(msg).hexdigest())
print()

msg2 = b"hello word"
print(msg2)
print("msg2_sha1:",sha1(msg2).hexdigest())
print("msg2_sha256:",sha256(msg2).hexdigest())
print("msg2_md5:",md5(msg2).hexdigest())