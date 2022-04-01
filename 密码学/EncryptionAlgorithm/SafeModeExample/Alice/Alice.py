"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : RSA.py
@Introduce: RSA 非对称加密

"""


from random import randint
from PublickeyCipher import *
from BlockCipher import *
from SequentialCipher import *
from Hash import *


Alice_path = "E:/EncryptionAlgorithm/EncryptionAlgorithm/SafeModeExample/Alice/"
Bob_path = "E:/EncryptionAlgorithm/EncryptionAlgorithm/SafeModeExample/Bob/"

def get_ID(name):
    md5 = MD5()
    if name == "Alice":
        return md5.md5(name)
    if name == "Bob":
        return md5.md5(name)

def get_random_number():
    # 16的字符串
    str1 = ""
    while len(str1) < 16:
        r = randint(0,16)
        str1 += str(hex(r))[2:]
    return str1

def get_encryption_key(ID,number):
    KeyList = [ord(symbol) for symbol in number]
    IDList =  [ord(symbol) for symbol in ID]
    # print(IDList)
    # print(len(IDList))
    aes = AES()
    key_list =  aes.key_expansion(KeyList)
    # for i in key_list:
    #     print(len(i))
    #     print(i)
    key = ""
    for i in range(len(IDList)):
        key += str(hex(key_list[3][i] + IDList[i]))[2:]
    return key


def digital_signature(message):

    sign = DigitalSignature()
    with open(Alice_path + 'RSA_sign_private_key.txt', 'r') as f:
        lines = f.readlines()
    d = int(lines[1][:-1])
    n = int(lines[3][:-1])
    sign = DigitalSignature()
    sign.set_private_key(d,n)
    # with open(Bob_path+'RSA_sign_public_key.txt', 'w') as f:
    #     f.write("e:\n" + str(e) + "\n")
    #     f.write("n:\n" + str(n) + "\n")
    # with open(Alice_path+'RSA_sign_private_key.txt', 'w') as f:
    #     f.write("d:\n" + str(d) + "\n")
    #     f.write("n:\n" + str(n) + "\n")
    return sign.sign(message)

############################################
def public_cipher(message):
    with open(Alice_path + 'Bob_RSA_public_key.txt', 'r') as f:
        lines = f.readlines()
    e = int(lines[1][:-1])
    n = int(lines[3][:-1])
    # print(lines)
    # print(d)
    # print(n)
    m = libnum.s2n(message)
    c = RSA.Encrypt(m,e,n)
    # print(c)
    return str(hex(c))[2:]

def public_cipher_decrypt(message):
    message = int(message,16)
    with open(Bob_path + 'Bob_RSA_private_key.txt', 'r') as f:
        lines = f.readlines()
    d = int(lines[1][:-1])
    n = int(lines[3][:-1])
    # print(lines)
    # print(d)
    # print(n)
    c = RSA.Decrypto(message,d,n)
    m = libnum.n2s(c)
    return str(bytes.decode(m))

# def get_RSA_sign_public_key():
#     e,n,d = RSA.get_keys(512)
#     with open(Bob_path + 'RSA_sign_public_key.txt', 'w') as f:
#         f.write("e:\n" + str(e) + "\n")
#         f.write("n:\n" + str(n) + "\n")
#     with open(Alice_path + 'RSA_sign_private_key.txt', 'w') as f:
#         f.write("d:\n" + str(d) + "\n")
#         f.write("n:\n" + str(n) + "\n")
#
#
# def get_RSA_KEY():
#     e,n,d = RSA.get_keys(512)
#     with open(Bob_path+'Bob_RSA_private_key.txt', 'w') as f:
#         f.write("d:\n" + str(d) + "\n")
#         f.write("n:\n" + str(n) + "\n")
#     with open(Alice_path+'Bob_RSA_public_key.txt', 'w') as f:
#         f.write("e:\n" + str(e) + "\n")
#         f.write("n:\n" + str(n) + "\n")


def Alice_main():
    # get_RSA_KEY()
    # 文件获取信息
    with open(Alice_path + 'message.txt', 'r') as f:
        message = f.read()
    print("明文为:")
    print(message)
    # 明文利用RSA数字签名进行签名
    digital_sign = digital_signature(message)
    print("数字签名：")
    print(digital_sign)
    # 获取ID
    ID = get_ID("Alice")
    # print(ID)
    # 获取随机数
    number = get_random_number()
    print("随机数为：")
    print(number)
    # 随机数进行RSA加密
    RSA_random_number = public_cipher(number)
    print("RSA加密后的随机数为")
    print(RSA_random_number)
    # 获取密钥进行加密
    encryption_key = get_encryption_key(ID,number)
    print("密钥为:")
    print(encryption_key)
    IV = "Bob"
    print("IV戳:")
    print(IV)
    cipher = Cipher()
    cipher_text = cipher.PCBC_Encrypt(message, encryption_key, IV)
    print("密文为:")
    print(cipher_text)
    C = []
    C.append("digital_sign")
    C.append(digital_sign)
    C.append("RSA_random_number")
    C.append(RSA_random_number)
    C.append("cipher_text")
    C.append(cipher_text)
    # 组合发送
    with open(Bob_path + 'cipher_text.txt', 'w') as f:
        for i in C:
            f.write(i + "\n")









if __name__ == '__main__':
    Alice_main()