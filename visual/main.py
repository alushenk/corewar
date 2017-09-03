#! /usr/bin/env python2.7

from __future__ import print_function
import sys
from collections import deque
import pygame


# champion = ' '.join(x.encode('hex') for x in a)
# print(' '.join(format(x, '02x') for x in memory))

# index = 0
# for i in range(64):
#     for j in range(64):
#         print(format(memory[index], '02x'), end=' ')
#         index += 1
#     print()

def main():
    memory = bytearray(4096)

    if len(sys.argv) == 2:
        with open(sys.argv[1], 'rb') as file:
            a = file.read()

            for i, byte in enumerate(a):
                memory[i] = byte
    else:
        print('ti pidor')
        exit()

    black = (0, 0, 0)
    green = (59, 171, 176)

    pygame.init()

    info = pygame.display.Info()
    size = width, height = info.current_w / 2, int(info.current_w * 0.4)

    screen = pygame.display.set_mode(size, pygame.RESIZABLE)
    screen.fill(black)

    index = 0
    for i in range(64):
        for j in range(64):
            size = 13
            space = 2
            pygame.draw.rect(screen, green, [i * (size + space), j * (size + space), size, size])
            # print(format(memory[index], '02x'), end=' ')
            index += 1

    loop = True
    while loop:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                loop = False
            if event.type == pygame.QUIT:
                loop = False
        pygame.display.update()

    pygame.quit()
    quit()


if __name__ == "__main__":
    main()
