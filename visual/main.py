#! /usr/bin/env python2.7

from __future__ import print_function
import sys
from collections import deque
import pygame
from parse import parse
import binascii

# colors
background_color = (39, 40, 34)
element_color = (70, 70, 70)
text_color = (180, 180, 180)
player_color = (0, 255, 0)
highlighted_text_color = (0, 0, 0)

# sizes
space = 1
element_size = 15
menu_width = 200
height = (element_size + space) * 64
width = height + menu_width

# temporary defines
player_start_index = 1
size = 12

# font
font_name = "sans"
font_size = element_size - 5


def draw_map(i, j, index, screen, font, field):
    x = j * (element_size + space)
    y = i * (element_size + space)
    if player_start_index <= index <= player_start_index + size:
        current_text_color = highlighted_text_color
        current_player_color = player_color
    else:
        current_text_color = text_color
        current_player_color = element_color
    pygame.draw.rect(screen, current_player_color, [x, y, element_size, element_size])

    # text = font.render(format(field[index] & 240, '02x')[0], True, current_text_color)
    # screen.blit(text, (x + size * 0.2, y + 3))
    # text = font.render(format(field[index] & 15, '02x')[1], True, current_text_color)
    # screen.blit(text, (x + size * 0.7, y + 3))

    # text = font.render(memory[index].encode('hex').upper(), True, current_text_color)
    # screen.blit(text, (x + 1, y  + 3))
    value = format(field[index], '02x').upper()
    text = font.render(value, True, current_text_color)
    screen.blit(text, (x + 2, y + 2))


def main(steps):
    pygame.init()

    screen = pygame.display.set_mode((
        int(width),
        int(height)),
        pygame.RESIZABLE)
    screen.fill(background_color)
    font = pygame.font.SysFont(
        font_name,
        font_size,
        bold=False,
        italic=False)

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
                    draw_map(i, j, index, screen, font, steps[0].field)
                    index += 1
        pygame.display.update()

    pygame.quit()
    quit()


if __name__ == "__main__":
    if len(sys.argv) == 2:
        with open(sys.argv[1], 'rb') as file:
            data = file.read()

        data = bytearray(data)
        steps = parse(data)

        main(steps)
    else:
        print('usage: ./main.py [output]')
        exit()
