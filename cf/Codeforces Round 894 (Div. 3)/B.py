T = int(input())

def solve():
  n = int(input())
  b = list(map(int, input().split()))
  a = []
  for i in range(n):
    if i == 0 or b[i] >= b[i-1]:
      a.append(b[i])
    else:
      a.extend([b[i], b[i]])
  print(len(a))
  print(" ".join(map(str, a)))
  
while T != 0:
  T -= 1
  solve()