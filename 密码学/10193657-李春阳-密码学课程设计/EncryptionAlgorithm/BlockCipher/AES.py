"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : AES.py
@Introduce: AES加密
"""

# nb = 4  # number of coloumn of State (for AES = 4)
# nr = 10  # number of rounds ib ciper cycle (if nb = 4 nr = 10)
# nk = 4  # the key length (in 32-bit words)


# S盒
sbox = [
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
]

# S盒的逆
inv_sbox = [
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
]

# 轮常值表
rcon = [[0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36],
        [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00],
        [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00],
        [0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00]
        ]


# AES类
class AES:
    """
    AES加密主体，实现了基本的128位的加密，解密
    """

    # 默认参数
    nb = 4  # 分组数量（对于AES = 4）。
    nr = 10  # 循环次数（如果nb = 4 nr = 10）。
    nk = 4  # 密钥长度（以32位字为单位）

    def __init__(self,nb=4,nr = 10,nk = 4):
        self.nb = nb
        self.nk = nk
        self.nr = nr

    # 加密函数
    def encrypt(self, input_bytes, key):
        """

        :param input_bytes:
        :param key:
        :return:
        """


        # 状态数组
        state = [[] for j in range(4)]
        for r in range(4):
            for c in range(self.nb):
                state[r].append(input_bytes[r + 4 * c])
        # 密钥扩展
        key_schedule = self.key_expansion(key)

        # 轮密钥加
        state = self.add_round_key(state, key_schedule)

        #循环9次的主体
        for rnd in range(1, self.nr):
            state = self.sub_bytes(state)
            state = self.shift_rows(state)
            state = self.mix_columns(state)
            state = self.add_round_key(state, key_schedule, rnd)

        #最后一次加密无列混合
        state = self.sub_bytes(state)
        state = self.shift_rows(state)
        state = self.add_round_key(state, key_schedule, rnd + 1)

        # 输出加密后列表
        output = [None for i in range(4 * self.nb)]
        for r in range(4):
            for c in range(self.nb):
                output[r + 4 * c] = state[r][c]

        return output

    # 解密函数
    def decrypt(self,cipher, key):
        """

        :param cipher:
        :param key:
        :return:
        """

        # 状态数组
        state = [[] for i in range(self.nb)]
        for r in range(4):
            for c in range(self.nb):
                state[r].append(cipher[r + 4 * c])
        # 密钥扩展
        key_schedule = self.key_expansion(key)
        # 倒的加
        state = self.add_round_key(state, key_schedule, self.nr)
        # 9次循环解密
        rnd = self.nr - 1
        while rnd >= 1:
            state = self.shift_rows(state, inv=True)
            state = self.sub_bytes(state, inv=True)
            state = self.add_round_key(state, key_schedule, rnd)
            state = self.mix_columns(state, inv=True)

            rnd -= 1

        # 最后一次的3次
        state = self.shift_rows(state, inv=True)
        state = self.sub_bytes(state, inv=True)
        state = self.add_round_key(state, key_schedule, rnd)

        # 输出结果
        output = [None for i in range(4 * self.nb)]
        for r in range(4):
            for c in range(self.nb):
                output[r + 4 * c] = state[r][c]

        return output

    # 密钥扩展
    def key_expansion(self,key):
        """
        密钥扩展，
        :param key:
        :return:
        """
        key_symbols = key
        # key_symbols = [ord(symbol) for symbol in key]

        # ChipherKey应该包含16个符号来填充4*4的表格。如果它少了用 "0x01 "来补充密钥
        if len(key_symbols) < 4 * self.nk:
            for i in range(4 * self.nk - len(key_symbols)):
                key_symbols.append(0x01)

        # ChipherKey 书上w
        key_schedule = [[] for i in range(4)]
        for r in range(4):
            for c in range(self.nk):
                key_schedule[r].append(key_symbols[r + 4 * c])

        # 继续填写KeySchedule
        for col in range(self.nk, self.nb * (self.nr + 1)):
            if col % self.nk == 0:
                # 4的倍数
                # 字循环
                tmp = [key_schedule[row][col - 1] for row in range(1, 4)]
                tmp.append(key_schedule[0][col - 1])

                # 字节替换
                for j in range(len(tmp)):
                    sbox_row = tmp[j] // 0x10
                    sbox_col = tmp[j] % 0x10
                    sbox_elem = sbox[16 * sbox_row + sbox_col]
                    tmp[j] = sbox_elem

                # 轮常量异或
                for row in range(4):
                    s = (key_schedule[row][col - 4]) ^ (tmp[row]) ^ (rcon[row][int(col / self.nk - 1)])
                    key_schedule[row].append(s)

            else:
                # 不是4的倍数，直接异或
                for row in range(4):
                    s = key_schedule[row][col - 4] ^ key_schedule[row][col - 1]
                    key_schedule[row].append(s)

        return key_schedule

    # 字节替换
    def sub_bytes(self,state, inv=False):
        """
        该转换将State中的每个元素替换为Sbox中的元素
        :param state: 状态矩阵
        :param inv: 是否是逆变换
        :return:
        """
        # encrypt S盒
        if inv == False:
            box = sbox
        # decrypt 逆S盒
        else:
            box = inv_sbox

        for i in range(len(state)):
            for j in range(len(state[i])):
                row = state[i][j] // 0x10
                col = state[i][j] % 0x10

                # Sbox是一个平面数组，故一次对应
                box_elem = box[16 * row + col]
                state[i][j] = box_elem

        return state

    def shift_rows(self,state, inv=False):
        """
        行位移
        第二轮旋转超过1个字节,第三行旋转了2个字节，第四行旋转了3个字节。这个转换并没有触及第一行。加密转换时使用左移，而在解密时则使用右移。
        :param state: 状态矩阵
        :param inv: 是否为逆
        :return:
        """

        count = 1
        # encrypting 左移
        if inv == False:
            for i in range(1, self.nb):
                state[i] = self.left_shift(state[i], count)
                count += 1
        # decryptionting 右移
        else:
            for i in range(1, self.nb):
                state[i] = self.right_shift(state[i], count)
                count += 1

        return state

    def mix_columns(self,state, inv=False):
        """
        这部分详细看书，就是定义的一个域
        当加密转换时，国家的每一列都乘以一个固定的多项式a(x)= {03}x**3 + {01}x**2 + {01}x + {02}在Galua领域。
        解密时乘以a'(x) = {0b}x**3 + {0d}x**2 + {09}x + {0e}。
        :param state: 状态矩阵
        :param inv: 是否为逆
        :return:
        """

        for i in range(self.nb):
            # encryption
            if inv == False:
                s0 = self.mul_by_02(state[0][i]) ^ self.mul_by_03(state[1][i]) ^ state[2][i] ^ state[3][i]
                s1 = state[0][i] ^ self.mul_by_02(state[1][i]) ^ self.mul_by_03(state[2][i]) ^ state[3][i]
                s2 = state[0][i] ^ state[1][i] ^ self.mul_by_02(state[2][i]) ^ self.mul_by_03(state[3][i])
                s3 = self.mul_by_03(state[0][i]) ^ state[1][i] ^ state[2][i] ^ self.mul_by_02(state[3][i])
            # decryption
            else:
                s0 = self.mul_by_0e(state[0][i]) ^ self.mul_by_0b(state[1][i]) ^ self.mul_by_0d(state[2][i]) ^ self.mul_by_09(state[3][i])
                s1 = self.mul_by_09(state[0][i]) ^ self.mul_by_0e(state[1][i]) ^ self.mul_by_0b(state[2][i]) ^ self.mul_by_0d(state[3][i])
                s2 = self.mul_by_0d(state[0][i]) ^ self.mul_by_09(state[1][i]) ^ self.mul_by_0e(state[2][i]) ^ self.mul_by_0b(state[3][i])
                s3 = self.mul_by_0b(state[0][i]) ^ self.mul_by_0d(state[1][i]) ^ self.mul_by_09(state[2][i]) ^ self.mul_by_0e(state[3][i])
            # 这里是一个矩阵相乘
            state[0][i] = s0
            state[1][i] = s1
            state[2][i] = s2
            state[3][i] = s3

        return state




    def add_round_key(self,state, key_schedule, round=0):
        """
        轮密钥加
        :param state: 状态矩阵
        :param key_schedule: 扩展密钥
        :param round: 次数
        :return:
        """


        for col in range(self.nk):
            # nb*round是一个移位，表示KeySchedule的一个部分的开始。
            s0 = state[0][col] ^ key_schedule[0][self.nb * round + col]
            s1 = state[1][col] ^ key_schedule[1][self.nb * round + col]
            s2 = state[2][col] ^ key_schedule[2][self.nb * round + col]
            s3 = state[3][col] ^ key_schedule[3][self.nb * round + col]

            state[0][col] = s0
            state[1][col] = s1
            state[2][col] = s2
            state[3][col] = s3

        return state


    """
    ############################################################################################################################################################################################
    ############################################################################################################################################################################################
    """


    def left_shift(self,array, count):
        """
        左移
        :param array: 列
        :param count: 位移
        :return:
        """

        res = array[:]
        for i in range(count):
            temp = res[1:]
            temp.append(res[0])
            res[:] = temp[:]

        return res

    def right_shift(self,array, count):
        """
        右移
        :param array: 列
        :param count: 位移
        :return:
        """

        res = array[:]
        for i in range(count):
            tmp = res[:-1]
            tmp.insert(0, res[-1])
            res[:] = tmp[:]

        return res


    """
    这里定义了列混合的一系列运算，参考了一些别人的经验
    """
    def mul_by_02(self,num):
        """The function multiplies by 2 in Galua space"""

        if num < 0x80:
            res = (num << 1)
        else:
            res = (num << 1) ^ 0x1b

        return res % 0x100

    def mul_by_03(self,num):
        """The function multiplies by 3 in Galua space
        example: 0x03*num = (0x02 + 0x01)num = num*0x02 + num
        Addition in Galua field is oparetion XOR

        """
        return (self.mul_by_02(num) ^ num)

    def mul_by_09(self,num):
        # return mul_by_03(num)^mul_by_03(num)^mul_by_03(num) - works wrong, I don't know why
        return self.mul_by_02(self.mul_by_02(self.mul_by_02(num))) ^ num

    def mul_by_0b(self,num):
        # return mul_by_09(num)^mul_by_02(num)
        return self.mul_by_02(self.mul_by_02(self.mul_by_02(num))) ^ self.mul_by_02(num) ^ num

    def mul_by_0d(self,num):
        # return mul_by_0b(num)^mul_by_02(num)
        return self.mul_by_02(self.mul_by_02(self.mul_by_02(num))) ^ self.mul_by_02(self.mul_by_02(num)) ^ num

    def mul_by_0e(self,num):
        # return mul_by_0d(num)^num
        return self.mul_by_02(self.mul_by_02(self.mul_by_02(num))) ^ self.mul_by_02(self.mul_by_02(num)) ^ self.mul_by_02(num)


"""
下面定义加密函数
"""

class AESCipher:


    def Encrypt(m, k):
        aes = AES()
        PlaintextList = [ord(symbol) for symbol in m]
        KeyList = [ord(symbol) for symbol in k]
        # print(PlaintextList)
        # print(KeyList)
        Ciphertext = []
        temp = []
        for byte in PlaintextList:
            temp.append(byte)
            if(len(temp) == 16):
                Cipherpart = aes.encrypt(temp,KeyList)
                Ciphertext.extend(Cipherpart)
                del temp[:]

        if 1 <= len(temp) < 16:
            empty_spaces = 16 - len(temp)
            for i in range(empty_spaces - 1):
                temp.append(0)
            temp.append(0)
            Cipherpart = aes.encrypt(temp, KeyList)
            Ciphertext.extend(Cipherpart)

        return Ciphertext



    def Decrypt(c, k):
        aes = AES()
        CiphertextList = []
        templist = c.split("0x")
        del templist[0]
        # print(templist)
        for type in templist:
            CiphertextList.append(eval("0x"+type))
        # print(CiphertextList)
        KeyList = [ord(symbol) for symbol in k]
        decrypted_data = []
        temp = []
        for byte in CiphertextList:
            temp.append(byte)
            if len(temp) == 16:
                decrypted_part = aes.decrypt(temp, KeyList)
                decrypted_data.extend(decrypted_part)
                del temp[:]

        if 0 < len(temp) < 16:
            empty_spaces = 16 - len(temp)
            for i in range(empty_spaces - 1):
                temp.append(0)
            temp.append(0)
            decrypted_part = aes.encrypt(temp, KeyList)
            decrypted_data.extend(decrypted_part)

        return decrypted_data

    def test():
        while True:
            print("*******************欢迎来到AES加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 \n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                s = input("请输入加密的明文:\n")
                k = input("请输入加密的密钥（小于16的字符串）:\n")
                if (s == "" or  k == ""):
                    print("输入错误，请重新输入")
                    continue
                if len(k) > 16:
                    print("密钥太长，请重新输入")
                    continue
                print(8*"*"+"  AES加密：  "+8*"*")
                Encryption = AESCipher.Encrypt(s,k)
                # print(Encryption)
                # 把list转为16进制字符串吧
                # print(Encryption)
                Encryption_str = ""
                for byte in Encryption:
                    Encryption_str += str(hex(byte))
                print("加密后的密文是:\n"+Encryption_str)

            elif op[0] == "2":
                s = input("请输入解密的密文(16进制字符串):\n")
                k = input("请输入解密的密钥（小于16的字符串）:\n")
                if(s == "" or k == ""):
                    print("输入错误，请重新输入")
                    continue
                if len(k) > 16:
                    print("密钥太长，请重新输入")
                    continue
                print(8*"*"+"  AES解密  "+8*"*")
                Decryption = AESCipher.Decrypt(s,k)
                # print(Decryption)
                # 把list转为字符串吧
                Decryption_str = ""
                for byte in Decryption:
                    Decryption_str += chr(byte)
                print("解密后的明文是:\n"+Decryption_str)

            else:
                print("输入错误，请重新输入")
                continue


if __name__ == '__main__':
    AESCipher.test()
    # crypted_data = []
    # temp = []
    # data = b'loveflag'
    # key1 = "2b7e151628aed2a6abf7158809cf4f3c"
    # data = b'loveflag'
    # key = "password"
    # data = [0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34]
    # data = [50, 67, 246, 168, 136, 90, 48, 141, 49, 49, 152, 162, 224, 55, 7, 52]
    data = [74, 65, 115, 105, 97, 32, 99, 97, 110, 32, 115, 101, 101, 32, 105, 116]
    s = ""
    for a in data:
        s += chr(a)
    print(s)
    # for a in data:
    #     print(a)
    AES = AES()
    # key = [0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c ]
    key = [112, 97, 115, 115, 119, 111, 114, 100]
    c = ""
    for a in key:
        c += chr(a)
    print(c)
    # [57, 37, 132, 29, 2, 220, 9, 251, 220, 17, 133, 151, 25, 106, 11, 50]
    # [50, 67, 246, 168, 136, 90, 48, 141, 49, 49, 152, 162, 224, 55, 7, 52]
    str = AES.encrypt(data,key)
    print(str)
    print(AES.decrypt(str,key))
    # for byte in data:
    #     temp.append(byte)
    #     if len(temp) == 16:
    #         crypted_part = AES.encrypt(temp, key)
    #         crypted_data.extend(crypted_part)
    #         del temp[:]
    # else:
    #     #padding v1
    #     # crypted_data.extend(temp)
    #
    #     # padding v2
    #     if 0 < len(temp) < 16:
    #         empty_spaces = 16 - len(temp)
    #         for i in range(empty_spaces - 1):
    #             temp.append(0)
    #         temp.append(1)
    #         crypted_part = AES.encrypt(temp, key)
    #         crypted_data.extend(crypted_part)
    # print(crypted_data)
    #
    # print("********************************************************")
    #
    # decrypted_data = []
    # temp = []
    # data = crypted_data
    # for byte in data:
    #     temp.append(byte)
    #     if len(temp) == 16:
    #         decrypted_part = AES.decrypt(temp, key)
    #         decrypted_data.extend(decrypted_part)
    #         del temp[:]
    # else:
    #     # padding v1
    #     # decrypted_data.extend(temp)
    #
    #     # padding v2
    #     if 0 < len(temp) < 16:
    #         empty_spaces = 16 - len(temp)
    #         for i in range(empty_spaces - 1):
    #             temp.append(0)
    #         temp.append(1)
    #         decrypted_part = AES.encrypt(temp, key)
    #         decrypted_data.extend(crypted_part)
    # print(decrypted_data)


    """
    JAsia can see it, but everyone's visibility is on time
    
    W£^¡èÌ@ïsSP1Vü1ï¸mB¹nªüI| JoRÇÞé)T8À^sÛuÆch´&-©Áf\
    
    0xee0x6b0xd30x8e0x9a0xac0x1f0x500xfe0xa10xaa0x50xe10x260xd0x9c0xd70x290xd70x5c0xf20x280x100xbe0xf80x410x80xb20x850x660xcb0xf70x30x5f0x150xe40x1d0x7a0x380x540xea0x790x2f0x630x140xc10xf80x5e0xa70x1e0x210x40x3d0x9c0x270x3c0xeb0xea0x1d0x3b0x5c0x430x5f0xb9
    0xee0x6b0xd30x8e0x9a0xac0x1f0x500xfe0xa10xaa0x50xe10x260x0d0x9c0xd70x290xd70x5c0xf20x280x100xbe0xf80x410x80xb20x850x660xcb0xf70x30x5f0x150xe40x1d0x7a0x380x540xea0x790x2f0x630x140xc10xf80x5e0xa70x1e0x210x40x3d0x9c0x270x3c0xeb0xea0x1d0x3b0x5c0x430x5f0xb9
    
[74, 65, 115, 105, 97, 32, 99, 97, 110, 32, 115, 101, 101, 32, 105, 116, 44, 32, 98, 117, 116, 32, 101, 118, 101, 114, 121, 111, 110, 101, 39, 115, 32, 118, 105, 115, 105, 98, 105, 108, 105, 116, 121, 32, 105, 115, 32, 111, 110, 32, 116, 105, 109, 101]
[112, 97, 115, 115, 119, 111, 114, 100]
[238, 107, 211, 142, 154, 172, 31, 80, 254, 161, 170, 5, 225, 38, 13, 156, 215, 41, 215, 92, 242, 40, 16, 190, 248, 65, 8, 178, 133, 102, 203, 247, 3, 95, 21, 228, 29, 122, 56, 84, 234, 121, 47, 99, 20, 193, 248, 94, 167, 30, 33, 4, 61, 156, 39, 60, 235, 234, 29, 59, 92, 67, 95, 185]

    
    """