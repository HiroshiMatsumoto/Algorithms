#!/usr/bin/env python
# -*- coding:utf-8 -*-
from SuffixArray.simple import suffix_array


def burrows_wheeler(text):
    tb = ["" for _ in range(len(text))]
    sa = suffix_array(text)
    for i in range(len(sa)):
        if sa[i][1] == '\0':
            tb[i] = text[-1 - 1]
        elif sa[i][1] > 0:
            tb[i] = text[ sa[i] - 1]
    return tb


def main():
    text = "hello world\0"
    sa = suffix_array(text)
    tb = burrows_wheeler(text)
    print(sa)
    print(tb)


if __name__ == "__main__":
    main()
