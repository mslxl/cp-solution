# -*- coding: utf-8 -*-
text = input()
dt = {}

for i in text:
    if i in dt:
        dt[i]+=1
    else:
        dt[i] = 1
        
nums = list(dt.keys())
nums.sort()
for k in nums:
    print("{}:{}".format(k, dt[k]))