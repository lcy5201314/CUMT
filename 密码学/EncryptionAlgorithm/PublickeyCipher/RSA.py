"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : RSA.py
@Introduce: RSA 非对称加密

"""

from random import randint
# from libnum import *
import libnum
import sys
import time
import gmpy2




def extended_gcd(a, b):
    """
    扩展的欧几里得算法计算gcd的最大公因子g以及x和y,满足g=ax+by
    :return: (g,s,t)
    """
    if b == 0:
        return a, 1, 0
    else:
        # 先得到更里层的x2,y2,
        g, x, y = extended_gcd(b, a % b)
        # 再根据得到的x2,y2,计算x1,y1
        return g, y, x - (a // b) * y


def mod_inverse(a, m):
    """
    计算模逆,即a**-1 (mod m)
    :param a: 底数
    :param m: 模数
    :return: 逆元
    """

    # ax + my = 1
    g, x, y = extended_gcd(a, m)
    # 若a,m不互素,则不可逆
    if g != 1:
        raise Exception(str(a) + '不可逆')
    else:
        return x % m


def fast_mod(x, n, p):
    x = x % p
    res = 1
    while n!=0:
        if n & 1:
            res = (res * x) % p
        n >>= 1
        x = (x * x) % p
    return res

"""
素性检验
"""

# Fermat素性检验
def Fermat(n, k=15):
    """
    用Fermat算法进行素性检验
    :param n: 被检验的数
    :param k: 检验的次数，默认为15次
    :return: 是否通过检验
    """
    # 偶数直接不通过
    if n % 2 == 0:
        return False

    for i in range(k):
        # 每次测试时,随机选取一个[2,n-2]的整数b
        b = randint(2, n - 2)
        g, x, y = extended_gcd(b, n)
        while g != 1:
            b = randint(2, n - 2)
            g, x, y = extended_gcd(b, n)
        r = pow(b,n-1,n)
        if r != 1:
            return False

    return True

# Solovay-Stassen 素性检验
def Solovay_Stassen(n, k=15):
    """
    用Solovay-Stassen算法进行素性检验
    :param n: 被检验的数
    :param k: 检验的次数，默认为15次
    :return: 是否通过检验
    """
    # 偶数直接不通过
    if n % 2 == 0:
        return False

    for i in range(k):
        # 每次测试时,随机选取一个[2,n-2]的整数b
        b = randint(2, n - 2)
        r = pow(b, (n-1)//2, n)

        if r != 1 and r != n-1:
            return False

        # 计算雅可比
        s = gmpy2.jacobi(b,n)
        s = s % n

        if s != r:
            return False

    return True











# Miler-Rabin素性检验
def miller_rabin(n, k=15):
    """
    用Miler-Rabin算法进行素性检验
    :param n: 被检验的数
    :param k: 检验的次数，默认为15次
    :return: 是否通过检验
    """
    # 偶数直接不通过
    if n % 2 == 0:
        return False

    # 分解s t 2^s*t
    t = n - 1
    s = 0
    while (t % 2 == 0):
        s += 1
        t = t // 2

    for i in range(k):
        # 每次测试时,随机选取一个[2,n-2]的整数b
        b = randint(2, n - 2)
        # 计算r0 = b^t mod n
        r = pow(b, t, n)
        if r == 1 or r == n - 1:
            continue
        else:
            for i in range(1, s):
                r = r * r % n
                if r == n - 1:
                    break
            else:
                return False

    return True





class RSA:



    def get_prime(n):
        """
        得到一个n位的素数(10进制表示)
        :param n: 二进制位数
        :return: n位素数(10进制表示)
        """
        while True:
            # 最高位为1,保证是n位
            num = '1'
            # 随机生成n-2位数
            for i in range(n - 2):
                x = randint(0, 1)
                num += str(x)
            # 最低位位1,保证是奇数
            num += '1'
            # 转为10进制
            num = int(num, 2)
            if miller_rabin(num):
                return num


    def get_keys(nbits):
        """
        :param nbits: 密钥长度(512/1024/2048...)
        :return: 公钥(e,n),私钥d
        """
        nbits = int(nbits)
        while True:
            p = RSA.get_prime(nbits)
            # print("p: " + str(p))
            q = RSA.get_prime(nbits)
            #print("q: " + str(q))
            # 保证p != q
            if p == q:
                continue

            N = p * q
            phiN = (p - 1) * (q - 1)
            e = randint(500, 10000)
            # 保证e与phiN互素
            if extended_gcd(e, phiN)[0] == 1:
                # 计算私钥
                # print("p: " + str(p))
                # print("q: " + str(q))
                d = mod_inverse(e, phiN)
                return e, N, d


    def Encrypt(m, e, n):
        e = int(e)
        n = int(n)
        c = pow(m, e, n)
        return c

    def Decrypto(c, d, n):
        d = int(d)
        n = int(n)
        m = pow(c, d, n)
        return m


    def test():
        while True:
            print("*******************欢迎来到RSA加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 \n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                m = input("请输入明文:\n")
                nbits = input("请输入位数:\n")
                if (m == "" or  nbits == ""):
                    print("输入错误，请重新输入")
                    continue
                e, n, d = RSA.get_keys(nbits)
                print("公钥e为: " + str(e))
                print("公钥n为: " + str(n))
                print("私钥d为: " + str(d))
                print("明文为: " + m)
                print(8*"*"+"  RSA加密：  "+8*"*")
                m = libnum.s2n(m)
                c = RSA.Encrypt(m, e, n)
                # print("密文为(10进制): " + str(c))
                print("加密后的密文是(16进制):")
                print(str(hex(c)[2:]))

            elif op[0] == "2":
                c = input("请输入密文(16进制):\n")
                # print(c)
                c = int(c,16)
                # print(c)
                d = input("请输入私钥d:\n")
                n = input("请输入公钥n:\n")
                print(8*"*"+"  RSA解密  "+8*"*")
                m = RSA.Decrypto(c, d, n)
                m = libnum.n2s(m)
                print("解密后的明文是:")
                print(bytes.decode(m))


            else:
                print("输入错误，请重新输入")
                continue


if __name__ == '__main__':
    n = RSA.get_prime(512)
    print(n)
    print(Fermat(n))
    print(Solovay_Stassen(n))
    print(miller_rabin(n))
    RSA.test()



"""
*******************欢迎来到RSA加密！！！*******************
请选择模式?
[0]退出 [1]加密 [2]解密 
1
请输入明文:
password
请输入位数:
512
公钥e为: 2587
公钥n为: 124212629194472047355390486574522702304343587194796373548560629633139441895163259867734941188302917642666293448384944223150160660209464485158981300066709185841318077547866954539506500111896887635523422560798248241265881635090680454800141337128977033932459448933591036892046435668375158957021801701639843963011
私钥d为: 113217386795734475324318039173840174732756930268778449488792410001910631615305360173219555980679659760884081929374448580667985634624629785854224161405991576182955083783721719068604670568773612732314498649950081545019852257608114300045239853254555468694165210844892650305573380009515689976554703585376269789331
明文为: password
********  RSA加密：  ********
加密后的密文是(16进制):
866d52fba244461effbc4d34c30257328fb7aaac861e000721018b30c536c7947de35e35fea8725d92f9b454b4ad28574aad5c52a741a9da6ab268d203c164046829d3f612f897f8c22394f473e890986612fe68ea2e9ead7d9de3cf3171478a679b7e26174620524027f3c18bbb31e275a1e0c0a3d849420c1f770fa440375e
*******************欢迎来到RSA加密！！！*******************
请选择模式?
[0]退出 [1]加密 [2]解密 
2
请输入密文(16进制):
866d52fba244461effbc4d34c30257328fb7aaac861e000721018b30c536c7947de35e35fea8725d92f9b454b4ad28574aad5c52a741a9da6ab268d203c164046829d3f612f897f8c22394f473e890986612fe68ea2e9ead7d9de3cf3171478a679b7e26174620524027f3c18bbb31e275a1e0c0a3d849420c1f770fa440375e
请输入私钥d:
113217386795734475324318039173840174732756930268778449488792410001910631615305360173219555980679659760884081929374448580667985634624629785854224161405991576182955083783721719068604670568773612732314498649950081545019852257608114300045239853254555468694165210844892650305573380009515689976554703585376269789331
请输入公钥n:
124212629194472047355390486574522702304343587194796373548560629633139441895163259867734941188302917642666293448384944223150160660209464485158981300066709185841318077547866954539506500111896887635523422560798248241265881635090680454800141337128977033932459448933591036892046435668375158957021801701639843963011
********  RSA解密  ********
解密后的明文是:
password
*******************欢迎来到RSA加密！！！*******************
请选择模式?
[0]退出 [1]加密 [2]解密 

"""