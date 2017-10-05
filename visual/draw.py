import time
import pygame
import numpy as np

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
highlighted_text_color = (0, 0, 0)
carriage_color = (25, 25, 25)

# player colors
player_colors = [(183, 102, 3), (41, 244, 126), (232, 23, 186), (25, 209, 252)]

# sizes
space = 1
element_size = 16
menu_width = 200
height = (element_size + space) * 64
width = height + menu_width

# font
# font_name = "raleway/Raleway-Thin.ttf"
font_name = "quicksand/Quicksand-Light.ttf"
font_size = element_size + 2

# shit here
run = 1

# pygame intitialization
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

info_font = pygame.font.SysFont(
    font_name,
    font_size + 10,
    bold=False,
    italic=False)


def text_objects(text, font):
    textSurface = font.render(text, True, text_color)
    return textSurface, textSurface.get_rect()


def button(msg, x, y, w, h):
    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()
    # print(click)
    if x + w > mouse[0] > x and y + h > mouse[1] > y:
        pygame.draw.rect(screen, (200, 200, 100), (x, y, w, h))

        if click[0] == 1:
            run *= -1
    else:
        pygame.draw.rect(screen, (100, 200, 100), (x, y, w, h))

    smallText = pygame.font.SysFont("comicsansms", 20)
    textSurf, textRect = text_objects(msg, smallText)
    textRect.center = ((x + (w / 2)), (y + (h / 2)))
    screen.blit(textSurf, textRect)


def draw_map(steps, players):
    iteration = 0
    loop = True

    size = element_size + space
    matrix = [(i * size, j * size) for j in range(64) for i in range(64)]

    while loop:
        # pygame.draw.rect(screen, highlighted_text_color, [width, height, 0, 0])
        pygame.draw.rect(screen, background_color, [width - menu_width, 0, menu_width, height])
        iteration_number = info_font.render(str(iteration), True, text_color)
        screen.blit(iteration_number, (width - 180, 100))

        button('huy', width - menu_width, 20, menu_width, 40)

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
            if event.type == pygame.QUIT:
                loop = False

            index = 0
            for x, y in matrix:
                current_text_color = text_color

                for carriage in steps[iteration].carriages:
                    if carriage.pc == index:
                        pygame.draw.rect(screen, carriage_color, [x, y, element_size, element_size])
                        break
                    elif index in carriage.addr_of_change:
                        pygame.draw.rect(screen, carriage_color, [x, y, element_size, element_size])
                        break
                else:
                    current_text_color = text_color
                    for player in players:
                        if player.pc <= index <= player.pc + player.size:
                            pygame.draw.rect(screen, player_colors[player.number - 1],
                                             [x, y, element_size, element_size])
                            current_text_color = highlighted_text_color
                            break
                    else:
                        pygame.draw.rect(screen, element_color, [x, y, element_size, element_size])

                value = format(steps[iteration].field[index], '02x').upper()
                text = font.render(value, True, current_text_color)
                screen.blit(text, (x + 1, y + 2))
                index += 1

        if run < 0:
            iteration += 1
        # pygame.display.update()
        pygame.display.flip()
        # clock.tick(20)

    pygame.quit()
    quit()
