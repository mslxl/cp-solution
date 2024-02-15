import random
T = random.randint(1, 50)
print(T)
for i in range(T):
  a,b, c= random.randint(1, 1e7), random.randint(1e7, 1e18), random.randint(1, 1e18)
  print(f"{a} {b} {c}")