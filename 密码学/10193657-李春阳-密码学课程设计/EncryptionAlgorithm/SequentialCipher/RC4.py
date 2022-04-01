"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : RC4.py
@Introduce: RC4 线性移位寄存器
"""
# 参考 https://www.cnblogs.com/gambler/p/9075415.html

import base64

class RC4:
    # RC4算法
    def RC4(text,key):
        ## 将0到255的互不重复的元素装入S盒。
        lk = len(key)
        # 先初始化状态向量S
        S = list(range(256))
        # 初始密钥（由用户输入），长度任意
        T = [key[i%lk] for i in range(256)]
        ## 根据密钥打乱S盒
        j = 0
        for i in range(256):
            j = (j+S[i]+ord(T[i])) % 256
            # 交换
            S[i],S[j] = S[j],S[i]
        ## 生成伪随机数，构造密文
        i = j = 0
        ans = ""
        for x in text:
            i = (i+1) % 256
            j = (j+S[i]) % 256
            S[i], S[j] = S[j], S[i]
            t = (S[i]+S[j]) % 256
            k = S[t]
            ans += chr(ord(x) ^ k)

        return ans

    # RC4加密: 明文转成base64编码的密文
    def Encrypt(message,key):
        # return base64.b64encode(RC4.RC4(message,key))
        return base64.b64encode(RC4.RC4(message,key).encode(encoding="utf-8")).decode()
        # return RC4.RC4(message,key)


    # RC4解密: base64编码的密文转成明文
    def Decrypt(cipher,key):
        return RC4.RC4(base64.b64decode(cipher.encode(encoding="utf-8")).decode(),key)
        # return RC4.RC4(base64.b64decode(cipher).decode(),key)
        # return RC4.RC4(cipher,key)

    # Main function
    def test():
        """
        测试案例
        :return:
        """
        while True:
            print("*******************欢迎来到RC4加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密\n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                s = input("请输入加密的明文:\n")
                k = input("请输入加密的密钥:\n")
                if (s == "" or k ==""):
                    print("输入错误，请重新输入")
                    continue
                print(8*"*"+"  RC4加密：  "+8*"*")
                Encryption = RC4.Encrypt(s,k)
                print("加密后的密文是:\n"+Encryption)

            elif op[0] == "2":
                s = input("请输入解密的密文:\n")
                k = input("请输入解密的密钥:\n")
                if (s == ""):
                    print("输入错误，请重新输入")
                    continue
                # ********  Decryption  ********
                print(8*"*"+"  RC4解密  "+8*"*")
                Decryption = RC4.Decrypt(s,k)
                print("解密后的明文是:\n"+Decryption)


            else:
                print("输入错误，请重新输入")
                continue



if __name__ == "__main__":
    RC4.test()

"""
base64编码
import base64

copyright = 'a123456'

def main():
    #转成bytes string
    bytesString = copyright.encode(encoding="utf-8")
    print("转化后的二进制:",bytesString)

    #base64 编码
    encodestr = base64.b64encode(bytesString)
    print("base64后的二进制:", encodestr)
    print("base64后的字符:",encodestr.decode())

    #解码
    decodestr = base64.b64decode(encodestr)
    print("base64后的二进制:", decodestr)
    print("base64后的字符:",decodestr.decode())

if __name__ == '__main__':
    main()
"""
