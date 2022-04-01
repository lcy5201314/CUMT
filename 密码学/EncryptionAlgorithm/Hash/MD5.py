"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : RSA.py
@Introduce: MD5 非对称加密
"""


import math
import re
import sys






"""
这里定义一些转换操作
"""

# 字符串转2进制
def str2bin(text):
    res = ''
    for i in text:
        tmp = bin(ord(i))[2:].zfill(8)
        res += tmp
    return res


# 大端序转小端序(16进制)
def hex2little(x):
    res = re.findall(r'.{2}', x)[::-1]
    res = ''.join(res)
    return res


# 大端序转小端序(2进制)
def bin2little(x):
    res = re.findall(r'.{8}', x)[::-1]
    res = ''.join(res)
    return res



class MD5():
    # 初始链接变量(小端序表示)
    IV_A, IV_B, IV_C, IV_D = (0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476)

    # 每轮步函数中循环左移的位数
    shift_ = ((7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22),
              (5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20),
              (4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23),
              (6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21))

    # 每步选择m得索引
    M_index_ = ((0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15),
                (1, 6, 11, 0, 5, 10, 15, 4, 9, 14, 3, 8, 13, 2, 7, 12),
                (5, 8, 11, 14, 1, 4, 7, 10, 13, 0, 3, 6, 9, 12, 15, 2),
                (0, 7, 14, 5, 12, 3, 10, 1, 8, 15, 6, 13, 4, 11, 2, 9))



    # 非线性函数F、G、H、I
    def F(self, x, y, z):
        return (x & y) | (~x & z)

    def G(self, x, y, z):
        return (x & z) | (y & ~z)

    def H(self, x, y, z):
        return x ^ y ^ z

    def I(self, x, y, z):
        return y ^ (x | (~z))

    # 生成伪随机常数
    def T(self, i):
        return math.floor(abs(math.sin(i)) * pow(2, 32))

    # 二进制的循环左移
    def rol(self, x, n):
        return (x << n) | (x >> 32 - n)

    # 模32加
    def mod_add(self, x, y):
        return (x + y) % pow(2, 32)

    # 对消息进行填充
    def message_padding(self,m):
        # 计算附加的64为长度(小端序表示)
        len_padding = bin2little(bin(len(m))[2:].zfill(64))
        m += '1'
        while len(m) % 512 != 448:
            m += '0'
        return m + len_padding

    # 压缩函数(对每个512bit分组进行处理)
    def compress_func(self, a, b, c, d, m):
        """
        压缩函数函数,对每512bit得分组进行处理,包括4轮,每轮16步
        :param a, b, c, d:  输入链接变量(即前一个分组的输出链接变量)
        :param m: 512bit的消息分组
        :return: A,B,C,D 输出链接变量
        """
        # 对每一分组的初始链接变量进行备份
        A, B, C, D = a, b, c, d
        # 将512bit分为16组,每组32bit
        m_list_32 = re.findall(r'.{32}', m)
        # 每个分组经过4轮函数
        for round_index in range(4):
            # 每轮有16步
            for step_index in range(16):
                # 对每一步的链接变量进行备份
                AA, BB, CC, DD = A, B, C, D
                # 每一轮选择不同的非线性函数
                if round_index == 0:
                    func_out = self.F(B, C, D)
                elif round_index == 1:
                    func_out = self.G(B, C, D)
                elif round_index == 2:
                    func_out = self.H(B, C, D)
                else:
                    func_out = self.I(B, C, D)
                A, C, D = D, B, C
                # B模加非线性函数的输出
                B = self.mod_add(AA, func_out)
                # 模加消息分组(注意为大端序)
                B = self.mod_add(B, int(bin2little(m_list_32[self.M_index_[round_index][step_index]]), 2))
                # print(type(B))
                # 模加伪随机常数
                B = self.mod_add(B, self.T(16 * round_index + step_index + 1))
                # 循环左移s位
                B = self.rol(B, self.shift_[round_index][step_index])
                # 模加BB
                B = self.mod_add(B, BB)
        # 与该分组的初始链接变量异或
        A = self.mod_add(A, a)
        B = self.mod_add(B, b)
        C = self.mod_add(C, c)
        D = self.mod_add(D, d)

        return A, B, C, D

    def md5(self,m):
        # 转为2进制
        m = str2bin(m)
        # 消息填充
        m = self.message_padding(m)
        # 对消息分组,每组512位
        m_list_512 = re.findall(r'.{512}', m)
        # 初始链接变量
        A, B, C, D = self.IV_A, self.IV_B, self.IV_C, self.IV_D
        # 对每512bit进行分组处理,前一组的4个输出连接变量作为下一组的4个输入链接变量
        for i in m_list_512:
            A, B, C, D = self.compress_func(A, B, C, D, i)
        # 把最后一次的分组4个输出连接变量再做一次大端小端转换
        A = hex2little(hex(A)[2:]).zfill(8)
        B = hex2little(hex(B)[2:]).zfill(8)
        C = hex2little(hex(C)[2:]).zfill(8)
        D = hex2little(hex(D)[2:]).zfill(8)
        # 拼接到一起的得到最终的md5值
        return A + B + C + D

    def test():
        while True:
            print("*******************欢迎来到MD5！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]压缩 \n").upper()
            if op[0] == "0":
                break

            elif op[0] == "1":
                cipher = MD5()
                print("请输入要进行md5的内容:")
                message = input()
                if len(str2bin(message)) > pow(2, 64):
                    print("最多只能处理2^64位！\n")
                    continue
                digest = cipher.md5(message)
                print("md5后的散列值为:")
                print(digest)

            else:
                print("输入错误，请重新输入")
                continue





if __name__ == '__main__':
    MD5.test()




"""
iscbupt

16838a414adaec12d8d86f735fd183b7
"""