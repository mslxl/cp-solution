# -*- coding: utf-8 -*-

f = int(input())
c = int(5 * (f - 32) // 9)
print("Celsius = {}".format(c if c >= 0 else c + 1), end='')