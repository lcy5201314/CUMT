"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : RSA.py
@Introduce: RSA 非对称加密

"""

from PublickeyCipher.RSA import *
from Hash.SHA256 import *


class DigitalSignature:

    def __init__(self,nbits = 512):
        self.hash = SHA256()
        self.e, self.n, self.d = RSA.get_keys(nbits)

    def set_public_key(self,e, n):
        self.e = e
        self.n = n

    def set_private_key(self,d, n):
        self.d = d
        self.n = n

    def sign(self,m):
        """

        :param m: 签名信息
        :return:
        """
        # 先用m产生消息的摘要
        digest = self.hash.hash(m)
        # 转为10进制
        digest = libnum.s2n(digest)
        # 对摘要进行签名
        sign_str = RSA.Encrypt(digest,self.d,self.n)
        return hex(sign_str)[2:]

    def check(self, m, s):
        """
        对签名进行验证
        :param m: 消息
        :param s: 消息的的签名
        :return: 是否通过验证
        """
        s = int(s, 16)
        # 先用md5产生消息的摘要
        digest = self.hash.hash(m)
        # 转为10进制
        digest = libnum.s2n(digest)
        # 用公钥对进行验证
        temp = RSA.Decrypto(s, self.e, self.n)
        if digest == temp:
            return True
        else:
            return False

    def test():
        while True:
            print("*******************欢迎来到RSA数字签名！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]数字签名 [2]签名验证 \n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                sign = DigitalSignature()
                print("请输入您要签名的消息:")
                message = input()
                e, n, d = sign.e, sign.n, sign.d
                print("e:", e)
                print("n:", n)
                print("d:", d)
                print("是否修改私钥：(Y/N)")
                option = input()
                if option[0] == "Y" or option[0] == "y":
                    print("请输入私钥d")
                    d = input()
                    print("请输入私钥n")
                    n = input()
                    sign.set_private_key(int(d), int(n))

                s = sign.sign(message)
                print("你的消息为:\n" + str(message))
                print("对应的签名为:\n" + str(s))

            elif op[0] == "2":
                sign = DigitalSignature()
                print("请输入您所得到签名:")
                signature = input()
                print("请输入与之对应的消息:")
                message = input()
                e, n, d = sign.e, sign.n, sign.d
                print("e:", e)
                print("n:", n)
                print("d:", d)
                print("是否修改公钥：(Y/N)")
                option = input()
                if option[0] == "Y" or option[0] == "y":
                    print("请输入公钥e")
                    e = input()
                    print("请输入公钥n")
                    n = input()
                    sign.set_public_key(int(e), int(n))

                if sign.check(message, signature):
                    print("验证成功!\n")
                else:
                    print("验证失败!\n")



            else:
                print("输入错误，请重新输入")
                continue




if __name__ == '__main__':
    DigitalSignature.test()

