# -*- coding: utf-8 -*-
print("ww")
dt = {'0': 'ling',
      '1': 'yi',
      '2': 'er',
      '3': 'san',
      '4': 'si',
      '5': 'wu',
      '6': 'liu',
      '7': 'qi',
      '8': 'ba',
      '9': 'jiu',
      '.': 'dian',
      '-': 'fu'}
tt = input()
print(dt[tt[0]], end='')
for i in tt[1:]:
    print(' ' + dt[i], end='')