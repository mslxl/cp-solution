#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math


def find_next_square(sq):
    n = math.sqrt(sq)
    if int(n) == n:
        return (math.sqrt(sq) + 1) ** 2
    else:
        return -1
