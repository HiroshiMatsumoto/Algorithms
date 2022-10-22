#!/usr/bin/env python
# -*- coding:utf-8 -*-
from BurrowsWheeler import suffix_array


def induced_sort(text):
    sa = suffix_array(text)
    sa = sorted(sa)

    type_s = []
    type_l = []
    type_s_star = []

    for i in range(len(sa)):
        if i == len(sa) - 1 or sa[i][1] < sa[i+1][1]:
            type_s.append(sa[i])
            if sa[i - 1] in type_l:
                type_s_star.append(sa[i])
        if i+1 < len(sa) and sa[i][1] > sa[i+1][1]:
            type_l.append(sa[i])
    LSs = ""
    for s in sa:
        if s in type_s_star:
            LSs += 'S*'
        elif s in type_s:
            LSs += 'S'
        if s in type_l:
            LSs += 'L'
    print(LSs)
    #
    # print(type_s_star)
    print(type_s)
    print(type_l)

    return sa


def main():
    text = "abracadabra\0"
    text = "abababab\0"
    induced_sort(text)


if __name__ == "__main__":
    main()