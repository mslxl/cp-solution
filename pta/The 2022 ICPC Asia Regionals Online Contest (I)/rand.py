import random

a = str(random.randint(1, 1e4))
b = str(random.randint(1, 1e4))

def conv(s: str):
  vs = ''
  for i in range(len(s)-1):
    vs += chr(ord('a') + (int(s[i: i+1]) % 26))
  return vs


print(conv(a))
print(conv(b))



