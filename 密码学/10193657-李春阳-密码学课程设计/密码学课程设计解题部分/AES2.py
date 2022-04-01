from Crypto.Cipher import AES
import base64
key_base64 = "6v3TyEgjUcQRnWuIhjdTBA=="
chiper_base64 = "rW4q3swEuIOEy8RTIp/DCMdNPtdYopSRXKSLYnX9NQe8z+LMsZ6Mx/x8pwGwofdZ"
key_16 = base64.b64decode(key_base64)
print(key_16)
ciphertext = base64.b64decode(chiper_base64)
decipher = AES.new(key_16, AES.MODE_ECB)
result =decipher.decrypt(ciphertext)
print (result)

from Crypto.Cipher import DES
import base64
key_base64 = "6v3TyEgjUcQRnWuIhjdTBA=="
chiper_base64 = "rW4q3swEuIOEy8RTIp/DCMdNPtdYopSRXKSLYnX9NQe8z+LMsZ6Mx/x8pwGwofdZ"
key_16 = base64.b64decode(key_base64)
ciphertext = base64.b64decode(chiper_base64)
decipher = DES.new(key_16, AES.MODE_ECB)
result =decipher.decrypt(ciphertext)
print (result)