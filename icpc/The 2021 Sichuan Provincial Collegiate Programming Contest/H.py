T = int(input())

for _ in range(T):
  verb = input()
  if verb == "ikimasu":
    print("itte")
    continue
  if verb.endswith("mimasu") or verb.endswith("bimasu") or verb.endswith("nimasu"):
    print(verb[:-6] + "nde")
    continue
  if verb.endswith("chimasu"):
    print(verb[:-7] + "tte")
    continue
  if verb.endswith("kimasu"):
    print(verb[:-6] + "ite")
    continue
  if verb.endswith('rimasu'):
    print(verb[:-6] + "tte")
    continue
  if verb.endswith('gimasu'):
    print(verb[:-6] + "ide")
    continue
  if verb.endswith('shimasu'):
    print(verb[:-7] + "shite")
    continue
  if verb.endswith('imasu'):
    print(verb[:-5] + "tte")
    continue
  
  
  