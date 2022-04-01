"""
@Time    : 2021/11/23
@Author  : LowlyLi
@Version : 1.0
@File    : VigenereCipher.py
@Introduce: VigenereCipher 维吉尼亚加密
"""
import numpy as np
import wordninja

class VigenereCipher:
    """
    维吉尼亚加密
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
        这是维吉尼亚加密的主体
        :param k: 密钥
        :param m: 明文
        :return:
        """
        k = k.upper()
        lm = len(m)
        lk = len(k)
        j = 0
        ans = ""
        for i in range(lm):
            if m[i].isupper():
                ans += chr(((ord(m[i]) - ord('A')) % 26 + (ord(k[j % lk]) - ord('A')) % 26) % 26 + ord('A'))
                j += 1
            elif m[i].islower():
                ans += chr(((ord(m[i]) - ord('a')) % 26 + (ord(k[j % lk]) - ord('A')) % 26) % 26 + ord('a'))
                j += 1
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
        k = k.upper()
        lc = len(c)
        lk = len(k)
        j = 0
        ans = ""
        for i in range(lc):
            if c[i].isupper():
                ans += chr(((ord(c[i]) - ord('A')) % 26 + 26 - (ord(k[j % lk]) - ord('A')) % 26) % 26 + ord('A'))
                j += 1
            elif c[i].islower():
                ans += chr(((ord(c[i]) - ord('a')) % 26 + 26 - (ord(k[j % lk]) - ord('A')) % 26) % 26 + ord('a'))
                j += 1
            else:
                ans += c[i]
        return ans

    def StatisticsDecrypt(cipher):
        print("开始获取密钥长度：")
        cipher = VigenereCipher.alpha(cipher)
        key_len = VigenereCipher.length(cipher)
        print("开始获取密钥")
        key = VigenereCipher.keyword(cipher, key_len)
        print("最终密钥为："+ key)
        plain = VigenereCipher.Decrypt(cipher, key)
        print("解密后明文为")
        print(plain)

        # 对英文文本进行分词
        print("语义整理后明文为：")
        word = wordninja.split(plain)
        plain = ''
        for i in range(len(word)):
            plain += word[i]
            plain += ' '
        print("明文为\n" + plain)
        print("明文为\n" + plain.lower())

        return

    # 预处理,去掉空格以及回车
    def alpha(cipher):
        c = ''
        for i in range(len(cipher)):
            if (cipher[i].isalpha()):
                c += cipher[i]
        return c

    # 给定字符串计算其重合指数
    def count_IC(cipher):
        count = [0 for i in range(26)]
        L = len(cipher)
        IC = 0.0
        for i in range(len(cipher)):
            if (cipher[i].isupper()):
                count[ord(cipher[i]) - ord('A')] += 1
            elif (cipher[i].islower()):
                count[ord(cipher[i]) - ord('a')] += 1
        for i in range(26):
            IC += (count[i] * (count[i] - 1)) / (L * (L - 1))
        return IC

    # 对字符串按输入个数进行分组，计算每一组的IC值返回平均值
    def count_key_len(cipher, key_len):
        N = ['' for i in range(key_len)]
        IC = [0 for i in range(key_len)]
        for i in range(len(cipher)):
            m = i % key_len
            N[m] += cipher[i]
        for i in range(key_len):
            IC[i] = VigenereCipher.count_IC(N[i])
        # print(IC)
        print("长度为%d时,平均重合指数为%.5f" % (key_len, np.mean(IC)))
        return np.mean(IC)

    def length(cipher):  # 遍历确定最有可能的密钥长度返回密钥长度
        key_len = 0
        mins = 100
        aver = 0.0
        for i in range(1, 20):
            k = VigenereCipher.count_key_len(cipher, i)
            if (abs(k - 0.065) < mins):
                mins = abs(k - 0.065)
                key_len = i
                aver = k
        print("密钥长度为%d,此时重合指数每组的平均值为%.5f" % (key_len, aver))
        return key_len

    def keyword(Ciphertext, keylength):
        ListCiphertext = list(Ciphertext)
        # 标准数据来源于课本
        Standard = {'A': 0.082, 'B': 0.015, 'C': 0.028, 'D': 0.043, 'E': 0.127, 'F': 0.022, 'G': 0.020, 'H': 0.061,
                    'I': 0.070, 'J': 0.002, 'K': 0.008, 'L': 0.040, 'M': 0.024, 'N': 0.067, 'O': 0.075, 'P': 0.019,
                    'Q': 0.001, 'R': 0.060, 'S': 0.063, 'T': 0.091, 'U': 0.028, 'V': 0.010, 'W': 0.023, 'X': 0.001,
                    'Y': 0.020, 'Z': 0.001}

        while True:
            KeyResult = []
            for i in range(keylength):
                # 使用切片分组
                PresentCipherList = ListCiphertext[i::keylength]
                # 初始化重合指数最大值为０，检验移动位数对应字符以＊代替
                QuCoincidenceMax = 0
                KeyLetter = "*"
                # 遍历移动的位数
                # m是密钥对应的英文字母
                for m in range(26):
                    # 初始化当前移动位数的重合互指数为０
                    MIC = 0
                    # 遍历计算重合指数：各个字符的频率＊对应英文字符出现的标准频率－－－的和
                    for Letter in set(PresentCipherList):
                        # fi/n
                        LetterFrequency = PresentCipherList.count(Letter) / len(PresentCipherList)
                        # 标准频率
                        k = chr((ord(Letter) - 65 - m) % 26 + 65)
                        StandardFrequency = Standard[k]
                        # 计算重合互指数，累加遍历26个英文字母
                        MIC += LetterFrequency * StandardFrequency
                    # 保存遍历过程中重合指数的最大值，同时保存对应应对的位数，即对应key的字符
                    if MIC > QuCoincidenceMax:
                        QuCoincidenceMax = MIC
                        # m是26个英文对应的位置，从0开始，+65是因为A在ascii中是65
                        KeyLetter = chr(m + 65)
                print("第", i + 1, "个密钥字母为:", KeyLetter, "对应的重合互指数为:", QuCoincidenceMax)
                # 保存当前位置key的值，退出循环，进行下一组子密文移动位数的尝试
                KeyResult.append(KeyLetter)
            # 列表转为字符串
            Key = "".join(KeyResult)
            break
        return Key



    # Main function
    def test():
        """
        测试案例
        :return:
        """
        while True:
            print("*******************欢迎来到维吉尼亚加密！！！*******************")
            op = input("请选择模式?\n[0]退出 [1]加密 [2]解密 [3]统计分析攻击\n").upper()

            if op[0] == "0":
                break

            elif op[0] == "1":
                s = input("请输入加密的明文:\n")
                k = input("请输入加密的密钥:\n")
                if (s == "" or  k == ""):
                    print("输入错误，请重新输入")
                    continue
                print(8*"*"+"  维吉尼亚加密：  "+8*"*")
                Encryption = VigenereCipher.Encrypt(s,k)
                print("加密后的密文是:\n"+Encryption)

            elif op[0] == "2":
                s = input("请输入解密的密文:\n")
                k = input("请输入解密的密钥:\n")
                if(s == "" or k == ""):
                    print("输入错误，请重新输入")
                    continue
                print(8*"*"+"  维吉尼亚解密  "+8*"*")
                Decryption = VigenereCipher.Decrypt(s,k)
                print("解密后的明文是:\n"+Decryption)

            elif op[0] == "3":
                # *******  统计分析攻击  *******
                s = input("请输入解密的密文(长一点的):\n")
                print(7 * "*" + " 统计分析攻击 " + 7 * "*")
                VigenereCipher.StatisticsDecrypt(s)

            else:
                print("输入错误，请重新输入")
                continue

if __name__ == '__main__':
    VigenereCipher.test()


    """
Though there is much to be concerned about, there is far, far more for which to be thankful. Though life’s goodness can at times be overshadowed, it is never outweighed.For every single act that is senselessly destructive, there are thousands more small, quiet acts of love, kindness and compassion. For every person who seeks to hurt, there are many, many more who devote their lives to helping and to healing.There is goodness to life that cannot be denied.In the most magnificent vistas and in the smallest details, look closely, for that goodness always comes shining through.There si no limit to the goodness of life. It grows more abundant with each new encounter. The more you experience and appreciate the goodness of life, the more there is to be lived.Even when the cold winds blow and the world seems to be cov ered in foggy shadows, the goodness of life lives on. Open your eyes, open your heart, and you will see that goodness is everywhere.Though the goodness of life seems at times to suffer setbacks, it always endures. For in the darkest moment it becomes vividly clear that life is a priceless treasure. And so the goodness of life is made even stronger by the very things that would oppose it.Time and time again when you feared it was gone forever you found that the goodness of life was really only a moment away. Around the next corner, inside every moment, the goodness of life is there to surprise and delight you.Take a moment to let the goodness of life touch your spirit and calm your thoughts. Then, share your good fortune with another. For the goodness of life grows more and more magnificent each time it is given away.Though the problems constantly scream for attention and the conflicts appear to rage ever stronger, the goodness of life grows stronger still, quietly, peacefully, with more purpose and meaning than ever before.
Ihgmcv kktrw ao alfw tg ta qfqrejfar redul, ldsih xs xsn, tru bojw bci zwiuz pc sh ihsfgtlo. Ihgmcv clue’k ykcuqtsk uwb rw iiewo pv rkejkdourlev, ap wj qtvwj kikztiyzar.Wrg enwnm jlcgdw wqk wwal ao gvqhedwogcb seklnitwxvw, ldsih prw ldclvpnvk icih hmsdh, elltt supg fi aonw, gwegcekk wbu fdmhsogzrc. Fgj ajvun pwjoce zwo kwayj wd hmjp, hyhge sja arqn, msfu afut wzg zsmrie lzawi oxvwk pc yhapafc oeg io zwwzzqv.Tzwns zv vogvjsjv io dabs kkpt usjbfw qe vwjwvg.Xn lza afvi msyjwwlrefl rwjwps sfz we wwe kewzchht vwpozoh, lggg qcrhedq, bci wwal ykcuqtsk shkrbh cgeag jkxnafc hyuduyz.Pvvut sa fk zzpxt lg pvv jdovfagj ru laxa. Wk jgook icih pbmfzoew lilz aotk ceo wjqfxctwj. Pvv pdrw qki vaeejaabth pnv sldihrisla hyh vogvjsjv df dabs, kkt mgja hyhge ak pc sh ainwz.Smhc wzwj hyh rodv swegh bdgs oeg ihw okfcg heweo hf et cgn afvg xn xgcup vwavgsg, kkt gggzbvvh ox detv oxvwk kb. Fstn qgqf vbts, ghab prjr zwwfk, dcd qgq kzoa sww pvrw vogvjsjv xs wnafpzwejw.Pvfxvh lza ufrsnwko cw oxfw kasdv pt laisj wd smxbsi vtttsyyj, li adowmj hcdmjag. Wrg if lds udgkwkp afptnl ap pvfdmwk rwmlslq uhsru ihsl hwwh xs s hnwthaekk pfvdhujw. Wbu vd tzw ccfgcekk kt clue ak iouh tvwf ohircgwj xm kkt vwju hylcgk ldok zdudv kdgrhe al.Pwdh pnv leav dvaaf svvq nom xaoihs il owg xrce xgnsmhg ygm bclqs tzsp hyh vogvjsjv df dabs ndh rwshzp rclq s icdhct sowm. Rudufv pvv qtxl ukfehg, ifkerv hkejq icdhct, lza ufrsnwko cw oxfw ao hyhge lg oiisgikw wbu gtlaydh prj.Tsca o drbefl pc chi tzw ccfgcekk kt clue lgqqy bduj klwili afv yocp nomj pvfxvhlk. Pvvq, hhsja mfxg gggz tfuiufw swkk pngldsi. Idr lza ufrsnwko cw oxfw yncnv bojw wbu pdrw ewueluiuwjh vdrh lais zw xs yarse dlaq.Ldcljw tzw lffeaeek yceviaflhm jfgese bci ditwfpwfq pnv lds trcfdayhj depwsn hf upgw wrsi virgfcsi, wwe ygkrehhs gx hwwh vrgoo gkudnywn gklal, imeskon, pwsyswxalq, oehy pdrw hqfgrhe sfz avdcify pvrq tvwj xswrge.
password
    
CHREE VOAHM AERAT BIAXX WTNXB EEOPH BSBQM QEQER BWRVX UOAKK AOSXX WEAHB WGJMM QMNKG RFVGX WTRZX WIAKL XFPSK AUTEM NDCMG TSXNX BTUIA DNGMG PSREL XNJEL XVRVP RTULH DNUWT WDTYG BPHXT FALJH ASVBF XNGLL CHRZB WELEK MSJIK NBHWR JGNMG JSGLX FEYPH AGNRB IEQJT AMRVL CRREM NDGLX RRIMG NSNRW CHRQH AEYEV TAQEB BIPEE WEVKA KOEWA DRENX NTBHH CHRTK DNVRZ CHRCL QOHPW QAIIW XNRMG WOIIF KEE

JANET

the almond tree was in tentative blossom the days were long rr often ending with magnificent evenings of corrugated pink sk jes the hunting season was over with hou nhs and guns put away for six months the vineyards were busy again as the well organized farmers treated their vines and the more lackadaisical neighbors hur r jeet odo the pruning they should have done in november 
 
    """