#!/usr/bin/env python
# -*- coding:utf-8 -*-
from SuffixArray.simple import suffix_array


def burrows_wheeler(text: str) -> list:
    """
    naive burrows wheeler implementation
    """
    tb = ["" for _ in range(len(text))]
    sa = suffix_array(text)
    for i in range(len(sa)):
        if sa[i][1] == '\0':
            tb[i] = text[-1 - 1]
        elif sa[i][0] > 0:
            tb[i] = text[sa[i][0] - 1]
    return tb


def main():
    text = "abracadabra\0"
    tb = burrows_wheeler(text)
    print(tb)


if __name__ == "__main__":
    main()
