"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : SHA256.py
@Introduce: SHA256 SHA256算法
https://blog.csdn.net/u011583927/article/details/80905740
"""

import re

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





class SHA256:
    def __init__(self):

        # 长度
        self.W = 32
        self.M = 1 << self.W
        self.FF = self.M - 1

        # 常数K
        self.constants = (
            0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
            0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
            0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
            0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
            0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
            0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
            0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
            0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
            0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
            0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
            0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
            0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
            0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
            0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
            0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
            0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2)

        # 压缩值
        self.compression_vals = (
            0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
            0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19)

    # 循环位移
    def ShiftRight(self, x, b):
        return ((x >> b) | (x << (self.W - b))) & self.FF

    # 填充
    def Pad(self, W):
        return bytes(W, "ascii") + b"\x80" + (b"\x00" * ((55 if (len(W) % 64) < 56 else 119) - (len(W) % 64))) + ((len(W) << 3).to_bytes(8, "big"))




    # 压缩函数主体
    def Compress(self, Wt, Kt, A, B, C, D, E, F, G, H):
        """
        s0 := (a rightrotate 2) xor (a rightrotate 13) xor(a rightrotate 22)
        maj := (a and b) xor (a and c) xor(b and c)
        t2 := s0 + maj
        s1 := (e rightrotate 6) xor (e rightrotate 11) xor(e rightrotate 25)
        ch := (e and f) xor ((not e) and g)
        t1 := h + s1 + ch + k[i] + w[i]
        h := g
        g := f
        f := e
        e := d + t1
        d := c
        c := b
        b := a
        a := t1 + t2

        :param Wt:
        :param Kt:
        :param A:
        :param B:
        :param C:
        :param D:
        :param E:
        :param F:
        :param G:
        :param H:
        :return:
        """
        s_0 = (self.ShiftRight(A, 2) ^ self.ShiftRight(A, 13) ^ self.ShiftRight(A, 22)) & self.FF
        maj = ((A & B) ^ (A & C) ^ (B & C)) & self.FF
        t2 = (s_0 + maj) & self.FF
        s_1 = (self.ShiftRight(E, 6) ^ self.ShiftRight(E, 11) ^ self.ShiftRight(E, 25)) & self.FF
        ch = ((E & F) ^ (~E & G)) & self.FF
        t1 = (H + s_1 +ch + Kt + Wt) & self.FF

        AA = (t1 + t2) & self.FF
        BB = A
        CC = B
        DD = C
        EE = (D + t1) & self.FF
        FF = E
        GG = F
        HH = G
        return AA, BB, CC, DD, EE, FF, GG, HH


    def hash(self, message):
        """

        :param message:
        :return:
        """
        # 填充1和若干的0
        message = self.Pad(message)
        # 初始化散列的缓存区
        digest = list(self.compression_vals)

        # 压缩函数，n组
        for i in range(0, len(message), 64):
            # 分片
            S = message[i: i + 64]
            # 扩展消息块 构造64个字
            # 对于每一块，将块分解为16个32-bit的big-endian的字
            W = [int.from_bytes(S[e: e + 4], "big") for e in range(0, 64, 4)]
            W = W + ([0] * 48)
            # 扩展消息块 构造64个字
            for j in range(16, 64):
                s_0 = self.ShiftRight(W[j - 15], 7) ^ self.ShiftRight(W[j - 15], 18) ^ (W[j - 15] >> 3)
                s_1 = self.ShiftRight(W[j - 2], 17) ^ self.ShiftRight(W[j - 2], 19) ^ (W[j - 2] >> 10)
                W[j] = (s_0 + W[j - 7] + s_1 + W[j - 16]) & self.FF

            # 初始化ABCDEFGH
            A, B, C, D, E, F, G, H = digest

            # 64 循环
            for j in range(64):
                A, B, C, D, E, F, G, H = self.Compress(W[j], self.constants[j], A, B, C, D, E, F, G, H)

        # 拼接输出
        h_result = []
        for x, y in zip(digest, (A, B, C, D, E, F, G, H)):
            result = (x + y) & self.FF
            h_result.append(result)

        str_result = b""
        for d in h_result:
            str_result += d.to_bytes(4, "big")

        result = ""
        for h in str_result:
            result += (format(h, "02x"))

        return result

    def test():
        while True:
            print("*******************欢迎来到SHA256！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]压缩 \n").upper()
            if op[0] == "0":
                break

            elif op[0] == "1":
                cipher = SHA256()
                print("请输入要进行SHA256的内容:")
                message = input()
                if len(str2bin(message)) > pow(2, 64):
                    print("最多只能处理2^64位！\n")
                    continue
                digest = cipher.hash(message)
                print("SHA256后的散列值为:")
                print(digest)

            else:
                print("输入错误，请重新输入")
                continue





if __name__ == "__main__":
    SHA256.test()



"""
password
5e884898da28047151d0e56f8dc6292773603d0d6aabbdd62a11ef721d1542d8
"""