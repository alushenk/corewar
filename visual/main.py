#! /usr/bin/env python
# #! /usr/bin/env python2.7

from __future__ import print_function
import sys

from parse import parse
from draw import draw_map


def main():
    if len(sys.argv) == 2:
        with open(sys.argv[1], 'rb') as file:
            data = file.read()

        data = bytearray(data)
        steps, players = parse(data)

        draw_map(steps, players)
    else:
        print('usage: ./main.py [output]')
        exit()


if __name__ == "__main__":
    main()
