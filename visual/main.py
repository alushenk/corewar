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

    background_color = (39, 40, 34)
    element_color = (70, 70, 70)
    text_color = (180, 180, 180)

    pygame.init()

    space = 2
    element_size = 20
    menu_width = 400
    height = (element_size + space) * 64
    width = height + menu_width

    screen = pygame.display.set_mode((int(width), int(height)), pygame.RESIZABLE)
    screen.fill(background_color)

    font = pygame.font.SysFont(False, 19, bold=False, italic=False, )
    index = 0
    for i in range(64):
        for j in range(64):
            x = j * (element_size + space)
            y = i * (element_size + space)
            pygame.draw.rect(screen, element_color, [x, y, element_size, element_size])

            text = font.render(format(memory[index], '02x'), True, text_color)
            screen.blit(text, (x + 2, y + 3))
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
