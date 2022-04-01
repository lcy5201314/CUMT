from SafeModeExample.Alice.Alice import *
from SafeModeExample.Bob.Bob import *

def get_RSA_sign_public_key():
    e,n,d = RSA.get_keys(512)
    print("d", d)
    print("n", n)
    print("e", e)
    with open(Bob_path + 'RSA_sign_public_key.txt', 'w') as f:
        f.write("e:\n" + str(e) + "\n")
        f.write("n:\n" + str(n) + "\n")
    with open(Alice_path + 'RSA_sign_private_key.txt', 'w') as f:
        f.write("d:\n" + str(d) + "\n")
        f.write("n:\n" + str(n) + "\n")


def get_RSA_KEY():
    e,n,d = RSA.get_keys(512)
    print("d",d)
    print("n",n)
    print("e",e)
    with open(Bob_path+'Bob_RSA_private_key.txt', 'w') as f:
        f.write("d:\n" + str(d) + "\n")
        f.write("n:\n" + str(n) + "\n")
    with open(Alice_path+'Bob_RSA_public_key.txt', 'w') as f:
        f.write("e:\n" + str(e) + "\n")
        f.write("n:\n" + str(n) + "\n")

def main():
    print("************************************************************")
    print("生成RSA私钥")
    print("************************************************************")
    print("************************************************************")
    print("Alice生成数字签名的公钥私钥")
    print("************************************************************")
    get_RSA_sign_public_key()
    print("************************************************************")
    print("Bob生成RSA公钥加密公钥私钥")
    print("************************************************************")
    get_RSA_KEY()
    print("************************************************************")
    print("Alice加密")
    print("************************************************************")
    Alice_main()
    print("************************************************************")
    print("Bob解密")
    print("************************************************************")
    Bob_main()


if __name__ == '__main__':
    main()