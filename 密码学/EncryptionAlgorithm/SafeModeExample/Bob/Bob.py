


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
    IDList = [ord(symbol) for symbol in ID]
    # print(IDList)
    # print(len(IDList))
    aes = AES()
    key_list = aes.key_expansion(KeyList)
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
    sign.set_private_key(d, n)
    # with open(Bob_path+'RSA_sign_public_key.txt', 'w') as f:
    #     f.write("e:\n" + str(e) + "\n")
    #     f.write("n:\n" + str(n) + "\n")
    # with open(Alice_path+'RSA_sign_private_key.txt', 'w') as f:
    #     f.write("d:\n" + str(d) + "\n")
    #     f.write("n:\n" + str(n) + "\n")
    return sign.sign(message)

def digital_signature_check(message,sign_text):
    sign = DigitalSignature()
    with open(Bob_path + 'RSA_sign_public_key.txt', 'r') as f:
        lines = f.readlines()
    e = int(lines[1][:-1])
    n = int(lines[3][:-1])
    sign = DigitalSignature()
    sign.set_public_key(e, n)
    # with open(Bob_path+'RSA_sign_public_key.txt', 'w') as f:
    #     f.write("e:\n" + str(e) + "\n")
    #     f.write("n:\n" + str(n) + "\n")
    # with open(Alice_path+'RSA_sign_private_key.txt', 'w') as f:
    #     f.write("d:\n" + str(d) + "\n")
    #     f.write("n:\n" + str(n) + "\n")
    return sign.check(message,sign_text)



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

def get_RSA_sign_public_key():
    e,n,d = RSA.get_keys(512)
    with open(Bob_path + 'RSA_sign_public_key.txt', 'w') as f:
        f.write("e:\n" + str(e) + "\n")
        f.write("n:\n" + str(n) + "\n")
    with open(Alice_path + 'RSA_sign_private_key.txt', 'w') as f:
        f.write("d:\n" + str(d) + "\n")
        f.write("n:\n" + str(n) + "\n")


def get_RSA_KEY():
    e,n,d = RSA.get_keys(512)
    with open(Bob_path+'Bob_RSA_private_key.txt', 'w') as f:
        f.write("d:\n" + str(d) + "\n")
        f.write("n:\n" + str(n) + "\n")
    with open(Alice_path+'Bob_RSA_public_key.txt', 'w') as f:
        f.write("e:\n" + str(e) + "\n")
        f.write("n:\n" + str(n) + "\n")


def Bob_main():
    # get_RSA_KEY()
    # 文件获取信息
    with open(Bob_path + 'cipher_text.txt', 'r') as f:
        lines = f.readlines()
    digital_sign = lines[1][:-1]
    RSA_random_number = lines[3][:-1]
    cipher_text = lines[5][:-1]
    print("密文是")
    print(cipher_text)
    print("RSA加密后的随机数为")
    print(RSA_random_number)
    print("数字签名：")
    print(digital_sign)
    # RSA解密还原随机数
    number = public_cipher_decrypt(RSA_random_number)
    print("随机数为：")
    print(number)
    ID = get_ID("Alice")
    # 获取密钥进行解密
    encryption_key = get_encryption_key(ID, number)
    print("密钥为:")
    print(encryption_key)

    IV = "Bob"
    print("IV戳:")
    print(IV)
    cipher = Cipher()
    cipher_text = cipher.PCBC_Decrypt(cipher_text, encryption_key, IV)
    print("明文为:")
    print(cipher_text)
    print("数字签名验证结果:")
    if digital_signature_check(cipher_text, digital_sign):
        print("验证成功!\n")
    else:
        print("验证失败!\n")
    # 验证
    with open(Bob_path + 'Decrypt_cipher_text.txt', 'w',encoding="utf-8") as f:
        f.write(cipher_text + "\n")
        if digital_signature_check(cipher_text, digital_sign):
            f.write("验证成功!\n")
        else:
            f.write("验证失败!\n")




if __name__ == '__main__':
    Bob_main()