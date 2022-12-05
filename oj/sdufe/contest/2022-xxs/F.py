n = int(input())
student = []
for id in range(n):
  data = [float(x) for x in input().split()]
  k = data[0]
  v = data[1:-1]
  score = data[-1]
  unappcet = False

  sigma = 0
  totalCredit = 0
  for i in range(0,2*k,2):
    if v[i+1] < 60:
      unappcet = True
    sigma+=(v[i] * v[i+1])
    totalCredit+=v[i]
    
  if totalCredit != 0:
    score *= 0.3
    score += (sigma / totalCredit) * 0.7
  student.append((score, unappcet))

student.sort(reverse=True)
fstCoin = round(n * 0.2)
totalCoin = round(n * 0.6)

coin = 0
for i in range(0, fstCoin):
  if not student[i][1]:
    coin += 800

for i in range(fstCoin, totalCoin):
  if not student[i][1]:
    coin += 400

print(int(coin))
