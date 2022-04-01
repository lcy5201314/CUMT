"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : HillCipher.py
@Introduce: HillCipher 希尔加密
"""
import numpy as np
from ClassicalCipher.ModMath import *

class HillCipher:
    """
    HillCipher
    希尔加密类
    """

    def kstr_make_k(k,n):
        """
        key 的转化，由str生成一个n*n的矩阵
        :param k: 密钥字符串
        :param n: 维度
        :return: 密钥矩阵
        """
        key = np.zeros([n, n])
        # print(k)
        p=0
        for i in range(n):
            for j in range(n):
                key[i][j] = ord(k[p]) - ord("A")
                p += 1
        return key

    def k_make_kstr(key,n):
        """
        key 的转化，由n*n的矩阵生成一个字符串str
        :param key: 矩阵
        :param n: 维度
        :return: 密钥字符串
        """
        num_k = []
        for i in key:  # 将密文向量转换为列表形式，且合并到一个列表
            for j in range(n):
                num_k.append(i[j])
        # print(num_k)
        c = [chr(int(i) + ord('A')) for i in num_k]
        return "".join(c)

    def strToMatrix(str,n):
        num_m = []
        temp = []
        count = 1
        for i in str:
            temp.append(ord(i) - ord('A'))
            if count % n == 0:
                num_m.append(temp)
                temp = []
            count += 1
        return num_m




    def Encrypt(m, n, k):
        """
        加密函数
        :param m: 明文
        :param n: 分段（维度）
        :param k: 字符串密钥
        :return: 密文
        """
        key = HillCipher.kstr_make_k(k,n)
        # print(key)
        num_m = HillCipher.strToMatrix(m,n)
        # print(num_m)
        result = np.array(num_m).dot(np.array(key))
        for i in result:
            for j in range(len(i)):
                i[j] %= 26
        num_c = []
        # 将密文向量转换为列表形式，且合并到一个列表
        for i in result:
            for j in range(n):
                num_c.append(i[j])
        # print(num_c)
        c = [chr(int(i) + ord('A')) for i in num_c]
        ans = "".join(c)
        return ans


    def Decrypt(c, n, k) -> str:
        """
        解密算法
        :param c: 密文
        :param n: 维度
        :param k: 字符串密钥
        :return: 明文
        """
        key = HillCipher.kstr_make_k(k, n)
        # print(key)
        # print(num_m)
        # print(key)
        num_m = HillCipher.strToMatrix(c, n)
        key = Mod_ni_materx(key,26)
        # print(key)
        result = np.array(num_m).dot(np.array(key))
        for i in result:
            for j in range(len(i)):
                i[j] %= 26
        num_c = []
        for i in result:  # 将密文向量转换为列表形式，且合并到一个列表
            for j in range(n):
                num_c.append(i[j])
        # print(num_c)
        c = [chr(int(i) + ord('A')) for i in num_c]
        ans = "".join(c)
        return ans

    def FindKey(c,m,n):
        num_m = HillCipher.strToMatrix(m, n)
        num_c = HillCipher.strToMatrix(c, n)
        # print(num_m)
        # print(num_c)
        key = Mod_ni_materx(num_m,26)
        # print(key)
        result = np.array(key).dot(np.array(num_c))
        Mod_materx(result,26)
        # print(result)
        return result







    # Main function
    def test():
        """
        测试案例
        :return:
        """
        while True:
            print("*******************欢迎来到希尔加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 [3]明文密文对应分析法 \n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                s = input("请输入加密的明文:\n").upper()
                print("请输入加密的分段:")
                n = int(input())
                print("请输入解密的密钥(长度为" + str(n*n) +"的字符串):")
                k = input().upper()
                if (len(k) != n * n):
                    print("密钥输入错误，请重新输入")
                    continue
                # print("请输入加密的密钥"+ n + "*" + n + "的可逆矩阵:")
                # k = np.zeros([n,n])
                # for i in range(n):
                #     k[i] = list(map(int, input().split(' ')))
                # print("输入的密钥为:")
                # print(k)
                print(8 * "*" + "  希尔加密：  " + 8 * "*")
                Encryption = HillCipher.Encrypt(s,n,k)
                print("加密后的密文是:\n" + Encryption)

            elif op[0] == "2":
                s = input("请输入解密的密文:\n").upper()
                print("请输入加密的分段:")
                n = int(input())
                print("请输入解密的密钥(长度为" + str(n * n) + "的字符串):")
                k = input().upper()
                if(len(k) != n*n):
                    print("密钥输入错误，请重新输入")
                    continue
                # print("请输入加密的密钥" + n + "*" + n + "的可逆矩阵:")
                # k = np.zeros([n, n])
                # for i in range(n):
                #     k[i] = list(map(int, input().split(' ')))
                # print("输入的密钥为:")
                # print(k)
                # # ********  Decryption  ********
                print(8 * "*" + "  希尔解密  " + 8 * "*")
                Decryption = HillCipher.Decrypt(s,n,k)
                print("解密后的明文是:\n" + Decryption)

            elif op[0] == "3":
                print("请输入明文：")
                m = str(input())
                print("请输入密文：")
                c = str(input())
                print("请输入密钥长度：")
                n = int(input())
                key = HillCipher.FindKey(c,m,n)
                print(8 * "*" + "  希尔破解  " + 8 * "*")
                print("密钥为：")
                print(key)
                print("密钥字符串为"+ HillCipher.k_make_kstr(key,n))

            else:
                print("输入错误，请重新输入")
                continue


if __name__ == '__main__':
    HillCipher.test()
    # # print("a************************************")
    # # n = int(input())
    # # k = input().upper()
    # # print(k)
    # # key = HillCipher.kstr_make_k(k,n)
    # # print(key)
    # # key = [[10,5,12,0,0],
    # #        [3,14,21,0,0],
    # #        [8,9,11,0,0],
    # #        [0,0,0,11,8],
    # #        [0,0,0,3,7]]
    # # k_ni = [[21,15,17,0,0],
    # #         [23,2,16,0,0],
    # #         [25,4,3,0,0],
    # #         [0,0,0,7,18],
    # #         [0,0,0,23,11]]
    # # print(np.array(key) @ np.array(k_ni))
    # # print("asdddddddddddddddddddddddddddddddddddddddd")
    # # print(HillCipher.k_make_kstr(key,5))
    # # m = "cyber"
    # # k = "KFMAADOVAAIJLAAAAALIAAADH"
    # # c = "wrtrv"
    # # # s = HillCipher.Encrypt(m.upper(),5,k)
    # # s = HillCipher.Decrypt(c.upper(),5,k)
    # # print(s)
    # # """
    # # cyber
    # # KFMAADOVAAIJLAAAAALIAAADH
    # # wrtrv
    # # """
    #
    #
    #
    # """
    # friday
    # 2
    # pocfku
    # """
    # # p = [[2,17,24,15,19],
    # #      [14,11,14,6,24],
    # #      [8,13,5,14,17],
    # #      [12,0,19,8,14],
    # #      [13,18,4,19,18]]
    # # c1 = [[3,22,21,14,19],
    # #       [25,12,7,8,8],
    # #       [3,7,8,23,23],
    # #       [12,23,15,0,6],
    # #       [8,15,6,3,18]]
    # # print(HillCipher.k_make_kstr(p,5))
    # # print(HillCipher.k_make_kstr(c1, 5))
    # # m = "CRYPTOLOGYINFORMATIONSETS"
    # # c = "DWVOTZMHIIDHIXXMXPAGIPGDS"
    # # n = 5
    # # k = HillCipher.FindKey(c.upper(),m.upper(),n)
    # # print(k)
    # # print(HillCipher.k_make_kstr(k,n))
    #
    # m = "frid".upper()
    # c = "pocf".upper()
    # n = 2
    # k = HillCipher.FindKey(c,m,n)
    # print(k)
    # print(HillCipher.k_make_kstr(k,n))
    # # HBIZ

    # # m = "CRYPTOLOGYINFORMATIONSETS"
    # # c = "DWVOTZMHIIDHIXXMXPAGIPGDS"
    # # key = "KFMAADOVAAIJLAAAAALIAAADH"
    # # n = 5

    # m = "frid".upper()
    # c = "pocf".upper()
    # n = 2