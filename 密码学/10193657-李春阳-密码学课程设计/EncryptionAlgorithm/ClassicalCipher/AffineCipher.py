"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : AffineCipher.py
@Introduce: AffineCipher  仿射加密
"""

from ClassicalCipher.ModMath import *




class AffineCipher:
    """
    AffineCipher
    这里实现仿射加密的类
    """
    def Encrypt(m,k1,k2) -> str:
        """
        加密算法
        :param m: 明文字符串
        :param k1: int数字
        :param k2: int数字
        :return: 密文c
        """
        k2 %= 26
        if gcd(k1, 26) != 1:
            print("k1必须和26互素,请重新输入")
            return ""
        l = len(m)
        ans = ""
        for i in range(l):
            if m[i].isupper():
                ans += chr((k1 * (ord(m[i]) - ord('A')) + k2) % 26 + ord('A'))
            elif m[i].islower():
                ans += chr((k1 * (ord(m[i]) - ord('a')) + k2) % 26 + ord('a'))
            else:
                ans += m[i]
        return ans

    def Decrypt(c, k1, k2):
        """
        :param c: 密文c
        :param k1: int数字
        :param k2: int数字
        :return: 明文
        """
        k2 %= 26
        if gcd(k1, 26) != 1:
            print("k1必须和26互素,请重新输入")
            return ""
        k1 = ModReverse(k1, 26)
        l = len(c)
        ans = ""
        for i in range(l):
            if c[i].isupper():
                ans += chr((k1 * (ord(c[i]) - ord('A') + 26 - k2)) % 26 + ord('A'))
            elif c[i].islower():
                ans += chr((k1 * (ord(c[i]) - ord('a') + 26 - k2)) % 26 + ord('a'))
            else:
                ans += c[i]
        return ans

    # Decryption(exhaustive)
    def BruteDecrypt(c):
        """
        就是依次遍历加密
        :param c: 密文
        :return:
        """
        for k1 in range(26):
            if gcd(k1, 26) == 1:
                for k2 in range(26):
                    print("k1 = " + str(k1).zfill(2)+", k2 = " + str(k2).zfill(2)+": " + AffineCipher.Decrypt(c, k1, k2))


    def StatisticsDecrypt(c):
        """

        :param c: 密文
        :return:
        """
        l = len(c)
        s = c.lower()
        statisticsDict = {}
        for i in range(26):
            statisticsDict[chr(ord("a") + i)] = 0
        for str in s:
            if str.isalpha():
                statisticsDict[str] = statisticsDict[str] + 1
        # print(statisticsDict)
        statisticsList = sorted(statisticsDict.items(),key=lambda x:x[1],reverse=True)
        # print(statisticsList)
        # numlist = statisticsList[0]
        # print(numlist)
        for k1 in range(26):
            if gcd(k1, 26) == 1:
                for k2 in range(26):
                    if chr(((ord("e") - ord("a")) * k1 + k2) % 26 + ord('a')) == statisticsList[0][0]:
                        print("k1 = {0}".format(k1) + ", k2 = {0}".format(k2) + ":" )
                        print(AffineCipher.Decrypt(c, k1, k2))


    # test
    def test():
        while True:
            print("*******************欢迎来到仿射加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 [3]爆破攻击 [4]统计分析攻击 \n").upper()

            if op[0] == "0":
                break
            elif op[0] == "1":
                # s = "Haha CUMTer~"
                # k1,k2 = 5,6
                s = input("请输入加密的明文:\n")
                k1 = int(input("请输入密钥k1(k1与26互素):\n"))
                k2 = int(input("请输入密钥k2:\n"))
                # ********  Encryption  ********
                print(8 * "*" + "  仿射加密  " + 8 * "*")
                Encryption = AffineCipher.Encrypt(s, k1, k2)
                if(Encryption != ""):
                    print("加密后的密文是: \n" + Encryption)

            elif op[0] == "2":
                s = input("请输入解密的密文:\n")
                k1 = int(input("请输入密钥k1(k1与26互素):\n"))
                k2 = int(input("请输入密钥k2:\n"))
                print(8 * "*" + "  仿射解密  " + 8 * "*")
                Decryption = AffineCipher.Decrypt(s, k1, k2)
                if(Decryption != ""):
                    print("解密后的明文是:\n" + Decryption)

            elif op[0] == "3":
                # *******  爆破攻击  *******
                s = input("请输入解密的密文:\n")
                print(7 * "*" + " 爆破攻击 " + 7 * "*")
                AffineCipher.BruteDecrypt(s)

            elif op[0] == "4":
                # *******  统计分析攻击  *******
                s = input("请输入解密的密文(长一点的):\n")
                print(7 * "*" + " 统计分析攻击 " + 7 * "*")
                AffineCipher.StatisticsDecrypt(s)

            else:
                print("输入错误，请重新输入")
                continue


if __name__ == '__main__':
    AffineCipher.test()
    s = "Pu yfo of oin hvy ufa hrpkpyb, jlar ph hopkk py oin hvy oinan, svo jn jpkk klvbi rfan zfyupgnyo zlkr; pu ovayng of ufvyg iph fjy hilgfj, lmmafmaplon nhzlmn, oin hvy jpkk sn oiafvbi oin inlao,jlar nlzi mklzn snipyg oin zfayna; pu ly fvohoanozing mlkr zlyyfo ulkk svoonaukx, oiny zknyzing jlcpyb larh, bpcny mfjna; pu P zly’o ilcn sapbio hrpkn, po jpkk ulzn of oin hvyhipyn, lyg hvyhipyn hrpkn ofbnoina, py uvkk skffr."
    AffineCipher.StatisticsDecrypt(s)

    """
    测试集
    明文：  Very happy to learn cryptography
    密钥： 5 5
    密文： Gzmv ofccv wx izfms pmvcwxjmfcov
    
    爆破:
If not to the sun for smiling, warm is still in the sun there, but we will laugh more confident calm; if turned to found his own shadow, appropriate escape, the sun will be through the heart,warm each place behind the corner; if an outstretched palm cannot fall butterfly, then clenched waving arms, given power; if I can’t have bright smile, it will face to the sunshine, and sunshine smile together, in full bloom.
k1 = 7, k2 = 11:
    
Pu yfo of oin hvy ufa hrpkpyb, jlar ph hopkk py oin hvy oinan, svo jn jpkk klvbi rfan zfyupgnyo zlkr; pu ovayng of ufvyg iph fjy hilgfj, lmmafmaplon nhzlmn, oin hvy jpkk sn oiafvbi oin inlao,jlar nlzi mklzn snipyg oin zfayna; pu ly fvohoanozing mlkr zlyyfo ulkk svoonaukx, oiny zknyzing jlcpyb larh, bpcny mfjna; pu P zly’o ilcn sapbio hrpkn, po jpkk ulzn of oin hvyhipyn, lyg hvyhipyn hrpkn ofbnoina, py uvkk skffr."
Pu yfo of oin hvy ufa hrpkpyb, jlar ph hopkk py oin hvy oinan, svo jn jpkk klvbi rfan zfyupgnyo zlkr; pu ovayng of ufvyg iph fjy hilgfj, lmmafmaplon nhzlmn, oin hvy jpkk sn oiafvbi oin inlao,jlar nlzi mklzn snipyg oin zfayna; pu ly fvohoanozing mlkr zlyyfo ulkk svoonaukx, oiny zknyzing jlcpyb larh, bpcny mfjna; pu P zly’o ilcn sapbio hrpkn, po jpkk ulzn of oin hvyhipyn, lyg hvyhipyn hrpkn ofbnoina, py uvkk skffr.
    
    """