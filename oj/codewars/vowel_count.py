#!/usr/bin/env python
# -*- coding: utf-8 -*-


def getCount(inputStr):
    num_vowels = 0
    vowels = "aeiou"
    for c in inputStr:
        if c in vowels:
            num_vowels += 1
    return num_vowels
