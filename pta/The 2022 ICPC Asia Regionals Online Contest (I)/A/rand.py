import random

value = bin(random.randint(2**3, 2**32))[2:]

testcase = 5
print(f"{len(value)} {testcase}")
print(value)
for i in range(testcase):
  a = random.randint(1, len(value) - 3)
  b = random.randint(1,  (len(value) - a) // 3)
  print(f"{a} {a + 3 * b - 1}")

