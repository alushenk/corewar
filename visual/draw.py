import time
import pygame
import numpy as np
import parse
# from os import system
# from platform import system as platform
# set up your Tk Frame and whatnot here...
# if platform() == 'Darwin':  # How Mac OS X is identified by Python
#     system('''/usr/bin/osascript -e 'tell app "Finder" to set frontmost of process "Python" to true' ''')

# text = font.render(format(step.field[index] & 240, '02x')[0].upper(), True, current_text_color)
# screen.blit(text, (x + 1, y + 3))
# text = font.render(format(step.field[index] & 15, '02x')[1].upper(), True, current_text_color)
# screen.blit(text, (x + 9, y + 3))

# text = font.render(memory[index].encode('hex').upper(), True, current_text_color)
# screen.blit(text, (x + 1, y  + 3))


clock = pygame.time.Clock()

# colors
background_color = (39, 40, 34)
element_color = (70, 70, 70)
text_color = (180, 180, 180)
menu_text_color = (255, 255, 255)
highlighted_text_color = (40, 40, 40)

player_colors = [(183, 102, 30), (41, 225, 126), (225, 30, 186), (30, 209, 225)]

carriage_colors = [(213, 132, 60), (71, 255, 156), (255, 60, 216), (60, 239, 255)]

change_colors = [(153, 72, 0), (11, 195, 96), (195, 0, 156), (0, 179, 195)]

# sizes
space = 1
element_size = 16
menu_width = element_size * 20
height = (element_size + space) * 64
width = height + menu_width

# font
font_name = "raleway/Raleway-Thin.ttf"
# font_name = "quicksand/Quicksand-Light.ttf"
# font_name = "comicsansms"
font_size = element_size + 2

run = 1


class Byte(object):
    def __init__(self, x, y):
        self.color = 0
        self.data = 0
        self.rect = 0
        self.x = x
        self.y = y


def text_objects(text, font):
    text_surface = font.render(text, True, text_color)
    return text_surface, text_surface.get_rect()


def button(screen, msg, x, y, w, h):
    global run
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()
    # print(click)
    if x + w > mouse[0] > x and y + h > mouse[1] > y:
        pygame.draw.rect(screen, (200, 200, 100), (x, y, w, h))

        if click[0] == 1:
            run *= -1
    else:
        pygame.draw.rect(screen, (100, 200, 100), (x, y, w, h))

    small_text = pygame.font.SysFont("comicsansms", 20)
    text_surf, text_rect = text_objects(msg, small_text)
    text_rect.center = ((x + (w / 2)), (y + (h / 2)))
    screen.blit(text_surf, text_rect)


def draw_map(file, players, indexes):
    pygame.init()

    screen = pygame.display.set_mode((
        int(width),
        int(height)),
        pygame.RESIZABLE
    )

    font = pygame.font.SysFont(
        font_name,
        font_size,
        bold=False,
        italic=False)

    info_font = pygame.font.SysFont(
        font_name,
        font_size + 10,
        bold=False,
        italic=False)

    global run
    iteration = 0
    loop = True

    size = element_size + space
    matrix = [Byte(i * size, j * size) for j in range(64) for i in range(64)]

    # players with them color
    for player in players:
        i = player.pc
        end = i + player.size
        color = player_colors[player.number - 1]
        while i < end:
            matrix[i].color = color
            i += 1

    while loop:

        step = parse.parse_step(file, indexes[iteration])

        # pygame events
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    loop = False
                elif event.key == pygame.K_RIGHT:
                    iteration += 1
                elif event.key == pygame.K_LEFT:
                    iteration -= 1
                elif event.key == pygame.K_SPACE:
                    run *= -1
                elif event.key == pygame.K_r:
                    iteration = 0
            if event.type == pygame.QUIT:
                loop = False

        # changes with player color
        for carriage in step.carriages:
            if carriage.is_change:
                color = change_colors[-carriage.player_number - 1]
                for addr in carriage.addr_of_change:
                    matrix[addr].color = color

        # simple squares
        for byte in matrix:
            color = byte.color if byte.color else element_color
            pygame.draw.rect(
                screen,
                color,
                [byte.x, byte.y, element_size, element_size]
            )

        # carriage itself
        for carriage in step.carriages:
            color = carriage_colors[-carriage.player_number - 1]
            pygame.draw.rect(
                screen,
                color,
                [matrix[carriage.pc].x, matrix[carriage.pc].y, element_size, element_size]
            )

        # text on top
        for i, byte in enumerate(matrix):
            current_text_color = text_color if not byte.color else highlighted_text_color

            value = format(step.field[i], '02x')
            # value = step.field[i].upper()
            text = font.render(value, True, current_text_color)
            screen.blit(text, (byte.x + 1, byte.y + 2))

        # menu items
        left = width - menu_width + 10
        status = info_font.render(
            'RUNNING' if run < 0 else 'PAUSED',
            True,
            menu_text_color
        )
        screen.blit(status, (left, 50))

        cycle = info_font.render(
            'Cycle : {}'.format(iteration),
            True,
            menu_text_color
        )
        screen.blit(cycle, (left, 100))

        processes = info_font.render(
            'Processes : {}'.format(len(step.carriages)),
            True,
            menu_text_color
        )
        screen.blit(processes, (left, 150))

        y = 200
        for player in players:
            name = info_font.render(
                'Player {} : {}'.format(player.number, player.name),
                True,
                menu_text_color
            )
            screen.blit(name, (left, y))
            y += 25

        # button(screen, 'huy', width - menu_width, 20, menu_width, 40)

        pygame.display.update()
        screen.fill(background_color)
        # clock.tick(100)

        if run < 0:
            iteration += 1

    pygame.quit()
    quit()
