# -*- coding: utf-8 -*-

N = int(input())
dt = {}
for _ in range(0,N):
    id, test_seat, exam_seat = input().split()
    dt[test_seat] = (id, exam_seat)
    
M = int(input())
ask = [x for x in input().split()]
for a in ask:
    print("{0[0]} {0[1]}".format(dt[a]))
