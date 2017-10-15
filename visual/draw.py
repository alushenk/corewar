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

player_colors = [(183, 102, 30), (41, 225, 126), (255, 5, 213), (76, 202, 211)]

carriage_colors = [(255, 160, 71), (183, 255, 203), (255, 158, 238), (183, 250, 255)]

change_colors = [(99, 50, 7), (35, 119, 51), (195, 0, 156), (12, 103, 109)]

# sizes
space = 1
element_size = 14
menu_width = element_size * 27
height = (element_size + space) * 64
width = height + menu_width
left_text_padding = width - menu_width + 10

# font
font_name = "raleway/Raleway-Thin.ttf"
# font_name = "quicksand/Quicksand-Light.ttf"
# font_name = "comicsansms"
font_size = element_size + 2

run = 1


class Byte(object):
    __slots__ = ['x', 'y']

    def __init__(self, x, y):
        self.x = x
        self.y = y


def get_color(number):
    mask = np.uint64(0xFF)
    r = np.bitwise_and(np.right_shift(number, np.uint64(16)), mask)
    g = np.bitwise_and(np.right_shift(number, np.uint64(8)), mask)
    b = np.bitwise_and(number, mask)
    return r, g, b


def set_color(color):
    x = 0
    x |= (color[0] << 16)
    x |= (color[1] << 8)
    x |= color[2]
    return x


def draw_map(file, players, indexes):
    pygame.init()

    screen = pygame.display.set_mode((
        int(width),
        int(height)),
        pygame.RESIZABLE | pygame.HWSURFACE | pygame.DOUBLEBUF
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
    last_iteration = 0
    iteration_count = len(indexes) - 1
    loop = True

    size = element_size + space

    bytes_matrix = [Byte(i * size, j * size) for j in range(64) for i in range(64)]
    color_matrix = np.zeros((len(indexes), 64 * 64), dtype=np.uint64)

    # players with them color
    for player in players:
        i = player.pc
        end = i + player.size
        color = player_colors[player.number - 1]
        while i < end:
            color_matrix[0][i] = set_color(color)
            i += 1

    while loop:

        if iteration == iteration_count and run < 0:
            run *= -1
        elif iteration == -1:
            iteration = iteration_count
        elif iteration == iteration_count + 1:
            iteration = 0

        step = parse.parse_step(file, indexes[iteration])
        if last_iteration < iteration:
            color_matrix[iteration] = color_matrix[iteration - 1]
        step_color = color_matrix[iteration]

        if iteration > last_iteration:
            last_iteration = iteration

        # pygame events
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    loop = False
                elif event.key == pygame.K_RIGHT:
                    if run < 0 < iteration:
                        color_matrix[iteration] = color_matrix[iteration - 1]
                    iteration += 1
                elif event.key == pygame.K_LEFT:
                    iteration -= 1
                elif event.key == pygame.K_SPACE:
                    run *= -1
                elif event.key == pygame.K_r:
                    iteration = 0
            if event.type == pygame.QUIT:
                loop = False

        # simple squares
        for i, byte in enumerate(bytes_matrix):
            color = element_color
            if step_color[i]:
                color = get_color(step_color[i])
            # color = byte.color if byte.color else element_color
            pygame.draw.rect(
                screen,
                color,
                [byte.x, byte.y, element_size, element_size]
            )

        # changes with player color
        # and
        # carriage itself
        menu_items = set()
        y = 225
        for carriage in step.carriages:
            if carriage.is_change:
                color = change_colors[-carriage.player_number - 1]
                color = set_color(color)
                for addr in carriage.addr_of_change:
                    step_color[addr] = color
                    # bytes_matrix[addr].color = color
            color = carriage_colors[-carriage.player_number - 1]
            pygame.draw.rect(
                screen,
                color,
                [bytes_matrix[carriage.pc].x, bytes_matrix[carriage.pc].y, element_size, element_size]
            )
            if carriage.player_number not in menu_items:
                last_live = info_font.render(
                    'Last live : {0:>43}'.format(carriage.last_live),
                    True,
                    menu_text_color
                )
                screen.blit(last_live, (left_text_padding, y))
                y += 25
                lives_in_period = info_font.render(
                    'Lives in current period : {0:>20}'.format(carriage.lives_in_period),
                    True,
                    menu_text_color
                )
                screen.blit(lives_in_period, (left_text_padding, y))
                menu_items.add(carriage.player_number)
                y += 50

        # text on top
        for i, byte in enumerate(bytes_matrix):
            current_text_color = text_color if not step_color[i] else highlighted_text_color

            value = format(step.field[i], '02x')
            # value = step.field[i].upper()
            text = font.render(value, True, current_text_color)
            screen.blit(text, (byte.x + 1, byte.y + 2))

        # menu items
        status = info_font.render(
            'RUNNING' if run < 0 else 'PAUSED',
            True,
            menu_text_color
        )
        screen.blit(status, (left_text_padding, 50))

        cycle = info_font.render(
            'Cycle : {}'.format(iteration),
            True,
            menu_text_color
        )
        screen.blit(cycle, (left_text_padding, 100))

        processes = info_font.render(
            'Processes : {}'.format(len(step.carriages)),
            True,
            menu_text_color
        )
        screen.blit(processes, (left_text_padding, 150))

        y = 200
        for player in players:
            color = player_colors[player.number - 1]
            name = info_font.render(
                'Player {} : {}'.format(player.number, player.name),
                True,
                color
            )
            screen.blit(name, (left_text_padding, y))
            y += 75

        # button(screen, 'huy', width - menu_width, 20, menu_width, 40)

        pygame.display.update()
        screen.fill(background_color)
        # clock.tick(100)

        if run < 0:
            iteration += 1

    pygame.quit()
    quit()
