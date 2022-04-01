# 添加包 后面会整合在一起
# from ClassicalCipher.CaesarCipher import CaesarCipher
# from ClassicalCipher.AffineCipher import AffineCipher
# from ClassicalCipher.VigenereCipher import VigenereCipher
from ClassicalCipher import *
from BlockCipher import *
if __name__ == '__main__':
    CaesarCipher.test()
    AffineCipher.test()
    VigenereCipher.test()
    HillCipher.test()


