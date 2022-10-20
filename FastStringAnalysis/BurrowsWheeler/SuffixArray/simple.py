#!/usr/bin/env python
# -*- coding:utf-8 -*-


def suffix_array(string):
    """
    """
    return sorted([(string[i:],i) for i in range(len(string))], key=lambda x:x[0])


def main():
    print(suffix_array("abracadabra"))


if __name__ == "__main__":
    main()

