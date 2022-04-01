"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : CaesarCipher.py
@Introduce: CaesarCipher  凯撒加密
"""

class CaesarCipher:
    """
    凯撒加密主体类。
    """

    # def __init__(self,key):
    #     """
    #     凯撒加密初始化
    #     :param key: 加密密钥
    #     """
    #     self.key1 = key

    # 加密
    def Encrypt(m,k):
        """
        这是凯撒加密的主体
        :param k: 密钥
        :param m: 明文
        :return:
        """
        k = k % 26
        ans = ""
        l = len(m)
        for i in range(l):
            if m[i].isupper():
                ans += chr((ord(m[i])-ord('A')+k)%26+ord('A'))
            elif m[i].islower():
                ans += chr((ord(m[i])-ord('a')+k)%26+ord('a'))
            else:
                ans += m[i]
        return ans

    # Decryption(normal)
    def Decrypt(c,k):
        """
        凯撒加密的解密函数
        :param c: 密文
        :param k: 密钥
        :return:
        """
        k %= 26
        ans = ""
        l = len(c)
        for i in range(l):
            if c[i].isupper():
                ans += chr((ord(c[i])-ord('A')+26-k)%26+ord('A'))
            elif c[i].islower():
                ans += chr((ord(c[i])-ord('a')+26-k)%26+ord('a'))
            else:
                ans += c[i]
        return ans

    # Decryption(exhaustive)
    def BruteCaesarDecrypt(cipher):
        for i in range(1,26):
            print("k = "+str(i).zfill(2)+": " + "  " + CaesarCipher.Decrypt(cipher,i))
            # print(CaesarCipher.Decrypt(cipher,i))

    # Main function
    def test():
        """
        测试案例
        :return:
        """
        while True:
            print("*******************欢迎来到凯撒加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 [3]爆破攻击 \n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                s = input("请输入加密的明文:\n")
                k = int(input("请输入加密的密钥(位移的距离，建议在1~25):\n"))
                if (s == ""):
                    print("输入错误，请重新输入")
                    continue
                print(8*"*"+"  凯撒加密：  "+8*"*")
                Encryption = CaesarCipher.Encrypt(s,k)
                print("加密后的密文是:\n"+Encryption)

            elif op[0] == "2":
                s = input("请输入解密的密文:\n")
                k = int(input("请输入解密的密钥(位移的距离，建议在1~25):\n"))
                if (s == ""):
                    print("输入错误，请重新输入")
                    continue
                # ********  Decryption  ********
                print(8*"*"+"  凯撒解密  "+8*"*")
                Decryption = CaesarCipher.Decrypt(s,k)
                print("解密后的明文是:\n"+Decryption)

            elif op[0] == "3":
                # *******  Brute Attack  *******
                s = input("请输入解密的密文:\n")
                print(7*"*"+"  爆破攻击   "+7*"*")
                CaesarCipher.BruteCaesarDecrypt(s)

            else:
                print("输入错误，请重新输入")
                continue

if __name__ == '__main__':
    CaesarCipher.test()

"""
If someone loves a flower, of which just one single blossom grows in all the millions and millions of stars, it is enough to make him happy just to look at the stars.If someone loves a flower, of which just one single blossom grows in all the millions and millions of stars, it is enough to make him happy just to look at the stars. He can say to himself, "Somewhere, my flower is there…" But if the sheep eats the flower, in one moment all his stars will be darkened… And you think that is not important!

5

Nk xtrjtsj qtajx f kqtbjw, tk bmnhm ozxy tsj xnslqj gqtxxtr lwtbx ns fqq ymj rnqqntsx fsi rnqqntsx tk xyfwx, ny nx jstzlm yt rfpj mnr mfuud ozxy yt qttp fy ymj xyfwx.Nk xtrjtsj qtajx f kqtbjw, tk bmnhm ozxy tsj xnslqj gqtxxtr lwtbx ns fqq ymj rnqqntsx fsi rnqqntsx tk xyfwx, ny nx jstzlm yt rfpj mnr mfuud ozxy yt qttp fy ymj xyfwx. Mj hfs xfd yt mnrxjqk, "Xtrjbmjwj, rd kqtbjw nx ymjwj…" Gzy nk ymj xmjju jfyx ymj kqtbjw, ns tsj rtrjsy fqq mnx xyfwx bnqq gj ifwpjsji… Fsi dtz ymnsp ymfy nx sty nrutwyfsy!
"""
