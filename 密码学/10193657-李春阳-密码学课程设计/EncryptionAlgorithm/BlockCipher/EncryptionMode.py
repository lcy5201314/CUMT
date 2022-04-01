"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : AffineCipher.py
@Introduce: AffineCipher  仿射加密
"""




import re
from BlockCipher.DES import *


class Cipher:

    def __init__(self):
        self.des = DES()


    # 字符串转2进制
    def str2bin(self,text):
        res = ''
        for i in text:
            tmp = bin(ord(i))[2:].zfill(8)
            res += tmp
        return res

    # 2进制转字符串
    def bin2str(self,bin_text):
        res = ""
        tmp = re.findall(r'.{8}', bin_text)
        for i in tmp:
            res += chr(int(i, 2))
        return res

    # 字符串转16进制
    def str2hex(self,text):
        res = ''
        for ch in text:
            tmp = hex(ord(ch))[2:].zfill(2)
            res += tmp
        return res

    # 16进制转字符串
    def hex2str(self,hex_text):
        res = ''
        tmp = re.findall(r'.{2}', hex_text)
        for i in tmp:
            res += chr(int('0x' + i, 16))
        return res

    # 预处理保证输入的密钥长度位为64位
    def key_process(self,key):
        # 小于64位补0
        if len(key) < 64:
            key += '0' * (64 - len(key))
        # 大于64位截断
        elif len(key) > 64:
            key = key[:64]
        return key

    # 预处理保证输入的明文长度位数为num的倍数,否则在后面补0
    def message_process(self,message, num):
        # 不是num的倍数,则补0
        if len(message) % num != 0:
            message += '0' * (num - (len(message) % num))
        return message

    def xor(slef, message, key):
        res = ''
        for i in range(len(message)):
            res += str(int(message[i]) ^ int(key[i]))
        return res

    def ECB_Encrypt(self,m,k):
        # 转换为2进制,并补全到64位的倍数
        message_bin = self.message_process(str2bin(m), 64)
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 将明文分组
        message_list = re.findall(r'.{64}', message_bin)
        cipher_bin = ''
        for i in message_list:
            cipher_bin += self.des.encrypt(i, key_bin)
        cipher = str2hex(bin2str(cipher_bin))
        return cipher

    def ECB_Decrypt(self,c,k):
        # 将明文进行预处理
        cipher_bin = str2bin(hex2str(c))
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 将密文分组
        cipher_list = re.findall(r'.{64}', cipher_bin)
        message_bin = ''
        for i in cipher_list:
            message_bin += self.des.decrypt(i, key_bin)
        # 明文2进制转字符串
        message = bin2str(message_bin).strip("\x00")
        return message

    def CBC_Encrypt(self,m,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # iv处理方式与key相同(少于8字节补0,大于8字节截断)
        iv_bin = self.key_process(str2bin(iv))
        # 将明文进行预处理
        message_bin = self.message_process(str2bin(m), 64)
        # 将明文分组
        message_list = re.findall(r'.{64}', message_bin)
        cipher_bin = ''
        # 第一组的反馈即为iv
        c = iv_bin
        for i in message_list:
            # 与反馈进行异或
            m = self.xor(c, i)
            c = self.des.encrypt(m, key_bin)
            # 链接密文分组
            cipher_bin += c
        cipher = str2hex(bin2str(cipher_bin))
        return cipher

    def CBC_Decrypt(self,c,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 对iv进行处理
        iv_bin = self.key_process(str2bin(iv))
        # 密文转2进制
        cipher_bin = str2bin(hex2str(c))
        # 对密文进行分组
        cipher_list = re.findall(r'.{64}', cipher_bin)
        message_bin = ''
        for i in cipher_list:
            temp = self.des.decrypt(i, key_bin)
            m = self.xor(iv_bin, temp)
            message_bin += m
            # 保存当前密文分组,用于下一个分组的解密异或
            iv_bin = i
        # 明文转换为字符串
        message = bin2str(message_bin).strip("\x00")
        return message

    def PCBC_Encrypt(self,m,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # iv处理方式与key相同(少于8字节补0,大于8字节截断)
        iv_bin = self.key_process(str2bin(iv))
        # 将明文进行预处理
        message_bin = self.message_process(str2bin(m), 64)
        # 将明文分组
        message_list = re.findall(r'.{64}', message_bin)
        cipher_bin = ''
        # 第一组的反馈即为iv
        c = iv_bin
        for i in message_list:
            # 与反馈进行异或
            m = self.xor(c, i)
            c = self.des.encrypt(m, key_bin)
            # 链接密文分组
            cipher_bin += c
            c = self.xor(c,i)
        cipher = str2hex(bin2str(cipher_bin))
        return cipher

    def PCBC_Decrypt(self,c,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 对iv进行处理
        iv_bin = self.key_process(str2bin(iv))
        # 密文转2进制
        cipher_bin = str2bin(hex2str(c))
        # 对密文进行分组
        cipher_list = re.findall(r'.{64}', cipher_bin)
        message_bin = ''
        for i in cipher_list:
            temp = self.des.decrypt(i, key_bin)
            m = self.xor(iv_bin, temp)
            message_bin += m
            # 保存当前密文分组,用于下一个分组的解密异或
            iv_bin = self.xor(m,i)
        # 明文转换为字符串
        message = bin2str(message_bin).strip("\x00")
        return message


    def CFB_Encrypt(self,m,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # iv处理方式与key相同(少于8字节补0,大于8字节截断)
        iv_bin = self.key_process(str2bin(iv))
        # 将明文进行预处理
        message_bin = self.message_process(str2bin(m), 64)
        # 将明文分组
        message_list = re.findall(r'.{64}', message_bin)
        cipher_bin = ''
        # 第一组的反馈即为iv
        k = iv_bin
        for i in message_list:
            # 先对iv进行加密
            c = self.des.encrypt(k,key_bin)
            m = self.xor(c,i)
            cipher_bin += m
            k = m
        cipher = str2hex(bin2str(cipher_bin))
        return cipher


    def CFB_Decrypt(self,c,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 对iv进行处理
        iv_bin = self.key_process(str2bin(iv))
        # 密文转2进制
        cipher_bin = str2bin(hex2str(c))
        # 对密文进行分组
        cipher_list = re.findall(r'.{64}', cipher_bin)
        message_bin = ''
        for i in cipher_list:
            temp = self.des.encrypt(iv_bin, key_bin)
            m = self.xor(i, temp)
            message_bin += m
            # 保存当前密文分组,用于下一个分组的解密异或
            iv_bin = i
        # 明文转换为字符串
        message = bin2str(message_bin).strip("\x00")
        return message

    def OFB_Encrypt(self,m,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # iv处理方式与key相同(少于8字节补0,大于8字节截断)
        iv_bin = self.key_process(str2bin(iv))
        # 将明文进行预处理
        message_bin = self.message_process(str2bin(m), 64)
        # 将明文分组
        message_list = re.findall(r'.{64}', message_bin)
        cipher_bin = ''
        # 第一组的反馈即为iv
        k = iv_bin
        for i in message_list:
            # 先对iv进行加密
            c = self.des.encrypt(k,key_bin)
            m = self.xor(c,i)
            cipher_bin += m
            k = c
        cipher = str2hex(bin2str(cipher_bin))
        return cipher


    def OFB_Decrypt(self,c,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 对iv进行处理
        iv_bin = self.key_process(str2bin(iv))
        # 密文转2进制
        cipher_bin = str2bin(hex2str(c))
        # 对密文进行分组
        cipher_list = re.findall(r'.{64}', cipher_bin)
        message_bin = ''
        for i in cipher_list:
            temp = self.des.encrypt(iv_bin, key_bin)
            m = self.xor(i, temp)
            message_bin += m
            # 保存当前密文分组,用于下一个分组的解密异或
            iv_bin = temp
        # 明文转换为字符串
        message = bin2str(message_bin).strip("\x00")
        return message

    def CTR_Encrypt(self,m,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # iv处理方式与key相同(少于8字节补0,大于8字节截断)
        iv_bin = self.key_process(str2bin(iv))
        # 将明文进行预处理
        message_bin = self.message_process(str2bin(m), 64)
        # 将明文分组
        message_list = re.findall(r'.{64}', message_bin)
        cipher_bin = ''
        # 第一组的反馈即为iv
        counter = iv_bin
        for i in message_list:
            # 先对iv进行加密
            c = self.des.encrypt(counter,key_bin)
            m = self.xor(c,i)
            cipher_bin += m
            counter = bin(int('0b' + counter, 2) + int('0b1', 2) % pow(2, 64))[2:].zfill(64)
        cipher = str2hex(bin2str(cipher_bin))
        return cipher


    def CTR_Decrypt(self,c,k,iv):
        # 将密钥转为2进制
        key_bin = self.key_process(str2bin(k))
        # 对iv进行处理
        iv_bin = self.key_process(str2bin(iv))
        # 密文转2进制
        cipher_bin = str2bin(hex2str(c))
        # 对密文进行分组
        cipher_list = re.findall(r'.{64}', cipher_bin)
        message_bin = ''
        # 第一组的反馈即为iv
        counter = iv_bin
        for i in cipher_list:
            temp = self.des.encrypt(counter, key_bin)
            m = self.xor(i, temp)
            message_bin += m
            counter = bin(int('0b' + counter, 2) + int('0b1', 2) % pow(2, 64))[2:].zfill(64)
        # 明文转换为字符串
        message = bin2str(message_bin).strip("\x00")
        return message

    def test():
        while True:
            print("*******************欢迎来到DES加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 \n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                while True:
                    print("请选择加密模式：[0]退出 [1]ECB [2]CBC [3]PCBC [4]CFB [5]OFB [6]CTR")
                    op_mode = input()
                    if op_mode[0] == "0":
                        break

                    elif op_mode[0] == "1":
                        s = input("请输入加密的明文:\n")
                        k = input("请输入加密的密钥:\n")
                        if (s == "" or k == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-ECB加密：  " + 8 * "*")
                        cipher = Cipher()
                        Encryption = cipher.ECB_Encrypt(s, k)
                        print("加密后的密文是:")
                        print(Encryption)

                    elif op_mode[0] == "2":
                        s = input("请输入加密的明文:\n")
                        k = input("请输入加密的密钥:\n")
                        iv = input("请输入加密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-CBC加密：  " + 8 * "*")
                        cipher = Cipher()
                        Encryption = cipher.CBC_Encrypt(s, k, iv)
                        print("加密后的密文是:")
                        print(Encryption)

                    elif op_mode[0] == "3":
                        s = input("请输入加密的明文:\n")
                        k = input("请输入加密的密钥:\n")
                        iv = input("请输入加密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-PCBC加密：  " + 8 * "*")
                        cipher = Cipher()
                        Encryption = cipher.PCBC_Encrypt(s, k, iv)
                        print("加密后的密文是:")
                        print(Encryption)

                    elif op_mode[0] == "4":
                        s = input("请输入加密的明文:\n")
                        k = input("请输入加密的密钥:\n")
                        iv = input("请输入加密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-CFB加密：  " + 8 * "*")
                        cipher = Cipher()
                        Encryption = cipher.CFB_Encrypt(s, k, iv)
                        print("加密后的密文是:")
                        print(Encryption)

                    elif op_mode[0] == "5":
                        s = input("请输入加密的明文:\n")
                        k = input("请输入加密的密钥:\n")
                        iv = input("请输入加密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-OFB加密：  " + 8 * "*")
                        cipher = Cipher()
                        Encryption = cipher.OFB_Encrypt(s, k, iv)
                        print("加密后的密文是:")
                        print(Encryption)

                    elif op_mode[0] == "6":
                        s = input("请输入加密的明文:\n")
                        k = input("请输入加密的密钥:\n")
                        iv = input("请输入加密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-CTR加密：  " + 8 * "*")
                        cipher = Cipher()
                        Encryption = cipher.CTR_Encrypt(s, k, iv)
                        print("加密后的密文是:\n")
                        print(Encryption)

                    else:
                        print("输入错误，请重新输入")
                        continue


            elif op[0] == "2":
                while True:
                    print("请选择加密模式：[0]退出 [1]ECB [2]CBC [3]PCBC [4]CFB [5]OFB [6]CTR")
                    op_mode = input()
                    if op_mode[0] == "0":
                        break

                    elif op_mode[0] == "1":
                        s = input("请输入解密的密文:\n")
                        k = input("请输入解密的密钥:\n")
                        if (s == "" or k == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-ECB解密：  " + 8 * "*")
                        cipher = Cipher()
                        Decryption = cipher.ECB_Decrypt(s, k)
                        print("解密后的明文是:")
                        print(Decryption)

                    elif op_mode[0] == "2":
                        s = input("请输入解密的密文:\n")
                        k = input("请输入解密的密钥:\n")
                        iv = input("请输入解密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-CBC解密：  " + 8 * "*")
                        cipher = Cipher()
                        Decryption = cipher.CBC_Decrypt(s, k, iv)
                        print("解密后的明文是:")
                        print(Decryption)

                    elif op_mode[0] == "3":
                        s = input("请输入解密的密文:\n")
                        k = input("请输入解密的密钥:\n")
                        iv = input("请输入解密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-PCBC解密：  " + 8 * "*")
                        cipher = Cipher()
                        Decryption = cipher.PCBC_Decrypt(s, k, iv)
                        print("解密后的明文是:")
                        print(Decryption)

                    elif op_mode[0] == "4":
                        s = input("请输入解密的密文:\n")
                        k = input("请输入解密的密钥:\n")
                        iv = input("请输入解密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-CFB解密：  " + 8 * "*")
                        cipher = Cipher()
                        Decryption = cipher.CFB_Decrypt(s, k, iv)
                        print("解密后的明文是:")
                        print(Decryption)

                    elif op_mode[0] == "5":
                        s = input("请输入解密的密文:\n")
                        k = input("请输入解密的密钥:\n")
                        iv = input("请输入解密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-OFB解密：  " + 8 * "*")
                        cipher = Cipher()
                        Decryption = cipher.OFB_Decrypt(s, k, iv)
                        print("解密后的明文是:")
                        print(Decryption)

                    elif op_mode[0] == "6":
                        s = input("请输入解密的密文:\n")
                        k = input("请输入解密的密钥:\n")
                        iv = input("请输入解密的初始向量:\n")
                        if (s == "" or k == "" or iv == ""):
                            print("输入错误，请重新输入")
                            continue
                        print(8 * "*" + "  DES-CTR解密：  " + 8 * "*")
                        cipher = Cipher()
                        Decryption = cipher.CTR_Decrypt(s, k, iv)
                        print("解密后的明文是:")
                        print(Decryption)

                    else:
                        print("输入错误，请重新输入")
                        continue


            else:
                print("输入错误，请重新输入")
                continue





if __name__ == "__main__":
   cipher = Cipher()
   m = "Though there is much to be concerned about, there is far"
   key = "password"
   iv = "2021-12-15"
   print("ECB")
   n = cipher.ECB_Encrypt(m,key)
   print(n)
   l = cipher.ECB_Decrypt(n,key)
   print(l)
   print("CBC")
   n = cipher.CBC_Encrypt(m,key,iv)
   print(n)
   l = cipher.CBC_Decrypt(n,key,iv)
   print(l)
   print("PCBC")
   n = cipher.PCBC_Encrypt(m, key, iv)
   print(n)
   l = cipher.PCBC_Decrypt(n, key, iv)
   print(l)
   print("CFB")
   n = cipher.CFB_Encrypt(m, key, iv)
   print(n)
   l = cipher.CFB_Decrypt(n, key, iv)
   print(l)
   print("OFB")
   n = cipher.OFB_Encrypt(m, key, iv)
   print(n)
   l = cipher.OFB_Decrypt(n, key, iv)
   print(l)
   print("CTR")
   n = cipher.CTR_Encrypt(m, key, iv)
   print(n)
   l = cipher.CTR_Decrypt(n, key, iv)
   print(l)
   Cipher.test()







