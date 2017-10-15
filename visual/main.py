#!/usr/bin/env python2.7
from __future__ import print_function
import sys
import os

from parse import parse
from draw import draw_map


def main():
    if len(sys.argv) == 2:
        file_name = sys.argv[1]
        file_size = os.path.getsize(file_name)

        with open(file_name, 'rb') as file:
            players, indexes = parse(file, file_size)
            draw_map(file, players, indexes)
    else:
        print('usage: ./main.py [output]')
        exit()


if __name__ == "__main__":
    main()
