#!/usr/bin/env python
# -*- coding: utf-8 -*-


def filter_list(l):
    return list(filter((lambda x: type(x) == int and x >= 0), l))
