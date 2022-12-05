n = int(input())
v = dict()

for i in range(n):
  name = input()
  if name in v:
    print(name + str(v[name]))
    v[name]+=1
  else:
    print("OK")
    v[name] = 1