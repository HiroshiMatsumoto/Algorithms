#!/usr/bin/env python
# -*- coding:utf-8 -*-
from BurrowsWheeler.SuffixArray.naive import suffix_array

TERMINAL = '\0'


def rank(text: str):
    return [text[:i + 1].count(text[i]) for i in range(len(text))]


def burrows_wheeler_transform(text: str) -> list:
    """
    naive burrows wheeler implementation
    """
    tb = ["" for _ in range(len(text))]
    sa = suffix_array(text)
    for i in range(len(sa)):
        if sa[i][0] > 0:
            tb[i] = text[sa[i][0] - 1]
        elif sa[i][0] == 0:
            tb[i] = text[-1]
    return tb


def decode(tf, tb) -> str:
    """
    """
    ranked_tb = list(zip(tb, rank(tb)))
    ranked_tf = list(zip(tf, rank(tf)))
    text = ""
    index = ranked_tb.index((TERMINAL, 1))
    while ranked_tf[index] != (TERMINAL, 1):
        char = ranked_tf[index]
        text += char[0]
        index = ranked_tb.index(ranked_tf[index])
    text += ranked_tf[index][0]
    return text


def main():
    text = "abracadabra"

    text += TERMINAL
    tb = burrows_wheeler_transform(text)
    sa = suffix_array(text)
    tf = [text[sa[i][0]] for i in range(len(text))]
    decoded_text = decode(tf, tb)

    assert text == decoded_text
    print(decoded_text)


if __name__ == "__main__":
    main()
