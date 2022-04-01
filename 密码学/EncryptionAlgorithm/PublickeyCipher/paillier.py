from phe import paillier # 开源库
import time # 做性能测试

# 测试paillier参数
print("默认私钥大小：",paillier.DEFAULT_KEYSIZE) #2048
# 生成公私钥
public_key,private_key = paillier.generate_paillier_keypair()
# 测试需要加密的数据
message_list = [3.1415926,100,-4.6e-12]
print(message_list)
# 加密操作
time_start_enc = time.time()
encrypted_message_list = [public_key.encrypt(m) for m in message_list]
time_end_enc = time.time()
print("加密耗时ms：",time_end_enc-time_start_enc)
for num in encrypted_message_list:
    print(num.ciphertext(False))
    print("")
    print(num.ciphertext(False).bit_length())
    print("")

# 解密操作
time_start_dec = time.time()
decrypted_message_list = [private_key.decrypt(c) for c in encrypted_message_list]
time_end_dec = time.time()
print("解密耗时ms：",time_end_dec-time_start_dec)
# print(encrypted_message_list[0])
print("原始数据:",decrypted_message_list)

# 测试加法和乘法同态
a,b,c = encrypted_message_list # a,b,c分别为对应密文

a_sum = a + 5 # 密文加明文
a_sub = a - 3 # 密文加明文的相反数
b_mul = b * 1 # 密文乘明文,数乘
c_div = c / -10.0 # 密文乘明文的倒数

print("a:",a.ciphertext()) # 密文a的纯文本形式
print("a_sum：",a_sum.ciphertext()) # 密文a_sum的纯文本形式
# print(a_sum.ciphertext(False))
print("a+5=",private_key.decrypt(a_sum))
print("a-3",private_key.decrypt(a_sub))
print("b*1=",private_key.decrypt(b_mul))
print("c/-10.0=",private_key.decrypt(c_div))

##密文加密文
print((private_key.decrypt(a)+private_key.decrypt(b)),"  ",private_key.decrypt(a+b))
#报错，不支持a*b，因为通过密文加实现了明文加的目的，这和原理设计是不一致的，只支持密文加！
# print((private_key.decrypt(a)+private_key.decrypt(b))==private_key.decrypt(a*b))



#!/usr/bin/env python3

"""Paillier encryption library for partially homomorphic encryption."""
import random

import phe
from phe import EncodedNumber, paillier
from phe.util import invert, powmod, getprimeover, isqrt
import numpy as np

# test
if __name__ == "__main__":
    print("***************************************************************************************************")
    public_key, private_key = paillier.generate_paillier_keypair(n_length=10)
    print('pub', public_key.g, public_key.n)
    print('priv', private_key.p, private_key.q)
    A=[3,32]
    print('A', A)
    enA=[public_key.encrypt(x) for x in A]
    print(enA[0].ciphertext())
    print(enA[0].ciphertext().bit_length())
    B=[4,16]
    print('B', B)
    enB=[public_key.encrypt(x) for x in B]
    print(enB[0].ciphertext())
    print(enB[0].ciphertext().bit_length())
    en=np.add(enA,enB)
    print(en[0].ciphertext())
    print(en[0].ciphertext().bit_length())
    for x in en:
        print(private_key.decrypt(x))
