T = int(input())
template = list("codeforces")
for _ in range(T):
  ans = 0
  for (a, b) in zip(template,input()):
    if a != b:
      ans += 1
  print(ans)