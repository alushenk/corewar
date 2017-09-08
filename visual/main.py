#! /usr/bin/env python2.7

from __future__ import print_function
import sys
from collections import deque
import pygame
from parse import parse_header

# champion = ' '.join(x.encode('hex') for x in a)
# print(' '.join(format(x, '02x') for x in memory))

background_color = (39, 40, 34)
element_color = (70, 70, 70)
text_color = (180, 180, 180)


def main():
    pygame.init()

    space = 2
    element_size = 20
    menu_width = 400
    height = (element_size + space) * 64
    width = height + menu_width

    screen = pygame.display.set_mode((int(width), int(height)), pygame.RESIZABLE)
    screen.fill(background_color)

    font = pygame.font.SysFont(False, 23, bold=False, italic=False, )

    player_start_index = 1
    player_color = (0, 255, 0)
    highlighted_text_color = (0, 0, 0)
    size = 12

    loop = True
    while loop:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE:
                loop = False
            if event.type == pygame.QUIT:
                loop = False
            index = 0
            for i in range(64):
                for j in range(64):
                    x = j * (element_size + space)
                    y = i * (element_size + space)
                    if player_start_index <= index <= player_start_index + size:
                        current_text_color = highlighted_text_color
                        current_player_color = player_color
                    else:
                        current_text_color = text_color
                        current_player_color = element_color
                    pygame.draw.rect(screen, current_player_color, [x, y, element_size, element_size])

                    # text = font.render(format(memory[index] & 240, '02x')[0], True, current_text_color)
                    # screen.blit(text, (x + 1, y + 3))
                    # text = font.render(format(memory[index] & 15, '02x')[1], True, current_text_color)
                    # screen.blit(text, (x + 10, y + 3))
                    text = font.render(memory[index].encode('hex')[0], True, current_text_color)
                    screen.blit(text, (x + 1, y + 3))
                    text = font.render(memory[index].encode('hex')[1], True, current_text_color)
                    screen.blit(text, (x + 10, y + 3))
                    index += 1
        pygame.display.update()

    pygame.quit()
    quit()


if __name__ == "__main__":
    if len(sys.argv) == 2:
        with open(sys.argv[1], 'r') as file:
            a = file.read()

        # memory = bytearray(4096)
        # for i, byte in enumerate(a):
        #     memory[i] = byte
        memory = 'z' * 4096
        parse_header(a)
        main()
    else:
        print('ti pidor')
        exit()
