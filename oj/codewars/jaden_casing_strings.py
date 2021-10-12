#!/usr/bin/env python
# -*- coding: utf-8 -*-


def to_jaden_case(string):
    return " ".join(map(lambda x:x.capitalize(), string.split()))
