T = int(input())

def solve():
  r, c = list(map(int, input().split()))
  s = [input() for i in range(r)]
  s[::] = [[row[i] for row in s[::-1]] for i in range(len(s[0]))]
  s = ["".join(i) for i in s]
  v, vi, vik, vika = [False, False, False, False]

  for line in s:
    if vik and 'a' in line:
      vika = True
    if vi and 'k' in line:
      vik = True
    if v and 'i' in line:
      vi = True
    if 'v' in line:
      v = True
  
  print("YES" if vika else "NO")
while T != 0:
  T -= 1
  solve()