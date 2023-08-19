T = int(input())

for ttt in range(T):
  n, c = list(map(int, input().split()))
  s = list(map(int, input().split()))

  def check(mid):
    sq = 0
    for si in s:
      edge = si + 2 * mid
      sq += edge * edge
    return sq <= c
  
  L = 0
  R = 21474836473
  while L < R:
    mid = (R + L + 1) // 2
    if check(mid):
      L = mid
    else:
      R = mid - 1
  print(L)