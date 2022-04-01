"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : RSA.py
@Introduce: RSA 非对称加密

"""

from random import randint
import libnum

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


def inv_mod(a, m):
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

def leftmost_bit(x):
    assert x > 0
    result = 1
    while result <= x:
        result = 2 * result
    return result // 2



class CurveFp(object):

    def __init__(self, p, a, b):
        """ 椭圆曲线方程y^2 = x^3 + a*x + b (mod p)."""
        self.p = p
        self.a = a
        self.b = b
        self.all_points = self.show_all_points()

    def __str__(self):
        s = "椭圆曲线参数(p={0:d}, a={1:d}, b={2:d})".format(self.p, self.a, self.b)
        s += "\n椭圆曲线为：y^2 = x^3 + {0}*x + {1} (mod {2})\n".format(self.a, self.b, self.p)
        s += "椭圆曲线上的点是："
        s += str(self.all_points)
        return s



    def check_point(self, x, y):
        return (y * y - (x * x * x + self.a * x + self.b)) % self.p == 0

    def show_all_points(self):
        points = []
        for x in range(self.p):
            for y in range(self.p):
                if (y * y - (x * x * x + self.a * x + self.b)) % self.p == 0:
                    points.append((x, y))
        return points








class Point():

    def __init__(self, curve, x, y, order=None):

        self.curve = curve
        self.x = x
        self.y = y
        # 阶
        self.order = order
        # self.curve 只有是INFINITY才可以是None
        if self.curve:
            assert self.curve.check_point(x, y)
        if order:
            assert self * order == INFINITY

    def __eq__(self, other):
        """两个点是否重合"""
        if self.curve == other.curve and self.x == other.x and self.y  == other.y :
            return True
        else:
            return False

    def __add__(self, other):
        """两个点‘相加’"""

        if other == INFINITY:
            return self
        if self == INFINITY:
            return other
        assert self.curve == other.curve

        if self.x % self.curve.p == other.x % self.curve.p:
            # y相反为0元，INFINITY
            if (self.y + other.y) % self.curve.p == 0:
                return INFINITY
            else:
                # 相等，等倍规则
                return self.double()

        p = self.curve.p
        l = ((other.y - self.y) * inv_mod(other.x - self.x, p)) % p
        #  x3 = l^2 - x1 -x2 , y3 = l*(x1-x3) - y1
        x3 = (l * l - self.x - other.x) % p
        y3 = (l * (self.x - x3) - self.y) % p

        return Point(self.curve, x3, y3)

    def __mul__(self, other):
        """
        左乘 Point * n(int)
        :param other: int倍率
        :return: Point点
        """
        n = other
        if self.order:
            n = n % self.order
         # 定义无限元的0
        if n == 0:
            return INFINITY
        if self == INFINITY:
            return INFINITY

        # 这里参考 类似快速幂的思想
        result = INFINITY
        addend = self
        while n != 0:
            if n & 1:
                result += addend
            n >>= 1
            addend = addend.double()

        # result = self
        # for i in range(e):
        #     result += self
        return result

    def __rmul__(self, other):
        """
        右乘 n(int) * Point
        :param other: int类型数字，
        :return: 左乘
        """
        return self * other

    def __str__(self):
        if self == INFINITY:
            return "infinity"
        return "({0},{1})".format(self.x, self.y)

    def double(self):
        """P=Q 倍点规则."""
        if self == INFINITY:
            return INFINITY

        p = self.curve.p
        a = self.curve.a
        # lamda : P = Q
        l = ((3 * self.x * self.x + a) * inv_mod(2 * self.y, p)) % p
        #  x3 = l^2 - x1 -x2 , y3 = l*(x1-x3) - y1
        x3 = (l * l - 2 * self.x) % p
        y3 = (l * (self.x - x3) - self.y) % p

        return Point(self.curve, x3, y3)


    # 逆元
    def invert(self):
        if self.y is None:
            return Point(None, None, None)
        return Point(self.curve, self.x, -self.y % self.curve.p)

    def isGenerator(self):
        i = 1
        while True:
            if i * self == self.invert():
                return True
            i += 1
        return False



INFINITY = Point(None, None, None)



class ECC():

    def __init__(self,p = 29,a = 4,b = 20):
        self.p = p
        self.a = a
        self.b = b
        self.curve = CurveFp(p, a, b)
        self.all_point = self.curve.all_points
        self.pointP1 = INFINITY
        self.pointP2 = INFINITY
        self.pointG = INFINITY


    def set_CurveFp(self, p, a, b):
        self.p = p
        self.a = a
        self.b = b
        self.curve = CurveFp(p, a, b)

    def get_all_point(self):
        print(1)
        print(self.curve.show_all_points())
        return self.curve.show_all_points()

    def set_pointG(self,x,y):
        self.pointG = Point(self.curve,x,y)

    def get_order(self):
        g = self.pointG
        n = 1
        while True:
            if n*g == g.invert():
                return n+1
            n += 1

    def get_public_key(self,private_key):
        return private_key * self.pointG


    def Encrypt(m,p,a,b,n,G,Q):
        # 先转换为m—》int
        plain_text = libnum.s2n(m)
        ecc = ECC(p,a,b)
        ecc.set_pointG(G[0],G[1])
        # 随机选取K
        k = randint(1, n)
        k_G = k * ecc.pointG  # 计算kG
        k_Q = k * Point(ecc.curve,Q[0].Q[1])  # 计算kQ
        # 随机选取Pt
        rad = randint(1, len(ecc.all_point))
        x, y = ecc.all_point[rad]
        P_t = Point(ecc.curve, x, y)
        cipher_text = plain_text * x + y
        C = [k_G, P_t + k_Q, cipher_text]
        return C

    def Decrypto():
        return m


def main():
    while True:
        # a = int(input("请输入椭圆曲线的参数a:"))
        # b = int(input("请输入椭圆曲线的参数b:"))
        # p = int(input("请输入椭圆曲线的参数p(p为质数):"))
        a = 13
        b = 22
        p = 23
        if (4 * (a ** 3) + 27 * (b ** 2)) % p == 0:
            print("选取的椭圆曲线不能用于加密，请重新选择\n")
        else:
            break
    ecc = ECC(p, a, b)
    print(ecc.curve)
    print("在上图中选出一个点作为生成元G")
    # G_x = int(input("你选取的横坐标G_x:"))
    # G_y = int(input("你选取的纵坐标G_y:"))
    G_x , G_y = 10,5
    ecc.set_pointG(G_x,G_y)
    # 获取该椭圆曲线的阶
    n = ecc.get_order()
    print(n)
    # 获取私钥并且key < 椭圆曲线的阶n
    private_key = int(input("输入私钥key(<%d):" % n))
    # 计算公钥 nG
    Q = ecc.get_public_key(private_key)
    print("生成公钥[a={0},b={1},p={2},阶{3},G{4},Q{5}]".format(a, b, p, n,ecc.pointG,Q))
    print("生成私钥[n:{0}]".format(private_key))



    # 加密开始
    k = randint(1,n)
    k = 13
    k_G = k * ecc.pointG  # 计算kG
    k_Q = k * Q # 计算kQ
    # rad = randint(1,len(ecc.all_point))
    # x,y = ecc.all_point[rad]
    x,y = 11,1
    P_t = Point(ecc.curve,x,y)
    plain_text = input("请输入要加密的明文：")
    plain_text = int(plain_text)
    # plain_text = "5"
    # plain_text = libnum.s2n(plain_text)
    #
    print(plain_text)
    # if plain_text > p:
    #     print("密文太长")
    cipher_text = plain_text * x + y

    # 密文为
    C = [k_G,P_t+k_Q,cipher_text]
    print("密文为：[kG:{0},P+KQ:{1},C:{2}]".format(k_G, P_t+k_Q, cipher_text))
    # 解密
    # 计算private_key*kG
    decrypto_P_t = C[1] + private_key * C[0].invert()
    decrypto_text = (C[2] - decrypto_P_t.y) / decrypto_P_t.x

    # text = libnum.n2s(decrypto_text)
    print("解密后的明文为:", int(decrypto_text))





if __name__ == '__main__':
    # plain_text = "password"
    # plain_text = libnum.s2n(plain_text)
    # print(plain_text)
    # p = 0XFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFF
    # a = 0xFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000FFFFFFFFFFFFFFFC
    # b = 0x28E9FA9E9D9F5E344D5A9E4BCF6509A7F39789F515AB8F92DDBCBD414D940E93
    # n = 0xFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFF7203DF6B21C6052B53BBF40939D54123
    # G = (0x32C4AE2C1F1981195F9904466A39C9948FE30BBFF2660BE1715A4589334C74C7,0xBC3736A2F4F6779C59BDCEE36B692153D0A9877CC62A474002DF32E52139F0A0)
    # GG = Point(CurveFp(p,a,b),G[0],G[1])
    # K = 20211221
    # QQ = K * GG
    # Q = (QQ.x,QQ.y)
    # c =  ECC.Encrypt("5",p,a,b,n,G,Q)
    # print(c)
    main()
    # p, a, b = 29, 4, 20
    # curve = CurveFp(p, a, b)
    # for x,y in curve.all_points:
    #     print("*************************")
    #     O = Point(curve, x, y)
    #     print(O)
    #     for i in range(1, curve.p + 1):
    #         print(i * O)

    # print(curve)
    # n = Point(curve, 6, 17)
    # print(n.isGenerator())
    # print(4*n)
    # print(n+n)
    # print(Point(curve,13,6) + Point(curve,13,6))
    # print(n+n+n+n)
    # print(leftmost_bit(21-16))
    # m = "password"
    # m = libnum.s2n(m)
    # print(m)
    # print(libnum.n2s(m))
    # n = bytes.decode(libnum.n2s(m))
    # print(n)
    # ecc = ECC()
    # print(ecc.order)



