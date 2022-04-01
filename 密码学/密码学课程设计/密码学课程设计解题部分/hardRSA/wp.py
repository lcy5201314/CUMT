import gmpy2  
import libnum  
import string



e = 2  
N = 87924348264132406875276140514499937145050893665602592992418171647042491658461  
p = 275127860351348928173285174381581152299  
q = 319576316814478949870590164193048041239  
# c=int(open('./flag.enc','rb').read().encode('hex'),16)  
# c1= open('./flag.enc','rb').read()
# c = int(to_bytes(c1),16)
c=int(open('./flag.enc','rb').read().hex(),16)  
cipher = c
inv_p = gmpy2.invert(p, q)
inv_q = gmpy2.invert(q, p)
mp = pow(cipher, (p + 1) // 4, p)
mq = pow(cipher, (q + 1) // 4, q)
a = (inv_p * p * mq + inv_q * q * mp) % N
b = N - int(a)
c = (inv_p * p * mq - inv_q * q * mp) % N
d = N - int(c)
for i in (a, b, c, d):
    s = '%x' % i
    if len(s) % 2 != 0:
        s = '0' + s
print(bytes.fromhex(s))





# inv_p = gmpy2.invert(p, q)
# inv_q = gmpy2.invert(q, p)
# mp = pow(cipher, (p + 1) / 4, p)
# mq = pow(cipher, (q + 1) / 4, q)
# a = (inv_p * p * mq + inv_q * q * mp) % N
# b = N - int(a)
# c = (inv_p * p * mq - inv_q * q * mp) % N
# d = N - int(c)
# for i in (a, b, c, d):
#     s = '%x' % i
#     if len(s) % 2 != 0:
#         s = '0' + s
# print s.decode('hex')