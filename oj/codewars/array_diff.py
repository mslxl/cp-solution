#!/usr/bin/env python
# -*- coding: utf-8 -*-


def array_diff(a, b):
    return list(filter((lambda x: x not in b), a))
