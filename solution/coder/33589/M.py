import random
import os
n,m = map(int, input().split())

G = []

for i in range(n):
  G.append(input())

A = []
B = []

for i in range(len(G)):
  al = ""
  bl = ""
  for j in G[i]:
    if j == '1':
      al+="1"
      bl+="1"
    else:
      random.seed(random.randrange(1,1000))
      l = random.randint(0,1)
      al += str(l)
      bl += "1" if l == 0 else "0"
  A.append(al)
  B.append(bl)

for i in A:
  print(i)

for i in B:
  print(i)


