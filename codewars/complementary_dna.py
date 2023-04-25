#!/usr/bin/env python
# -*- coding: utf-8 -*-


def DNA_strand(dna):
    dict = {
        'A': 'T',
        'T': 'A',
        'G': 'C',
        'C': 'G'
    }
    return "".join(map((lambda x: dict[x]), dna))
