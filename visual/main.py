#!/usr/bin/env python2.7
from __future__ import print_function
import contextlib
import sys
import os

from parse import parse
from draw import draw_map


@contextlib.contextmanager
def ignore_stderr():
    devnull = os.open(os.devnull, os.O_WRONLY)
    old_stderr = os.dup(2)
    sys.stderr.flush()
    os.dup2(devnull, 2)
    os.close(devnull)
    try:
        yield
    finally:
        os.dup2(old_stderr, 2)
        os.close(old_stderr)


def main():
    if len(sys.argv) == 2:
        file_name = sys.argv[1]
        file_size = os.path.getsize(file_name)

        with open(file_name, 'rb') as file:
            players, indexes, steps = parse(file, file_size)
            with ignore_stderr():
                draw_map(file, players, indexes, steps)
    else:
        print('usage: ./main.py [output]')
        exit()


if __name__ == "__main__":
    main()
