import pygame

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


def render(i, j, index, screen, font, step, players):
    busy = 0
    current_text_color = text_color

    x = j * (element_size + space)
    y = i * (element_size + space)

    for carriage in step.carriages:
        if carriage.pc == index:
            pygame.draw.rect(screen, carriage_color, [x, y, element_size, element_size])
            busy = 1

    if not busy:
        current_text_color = text_color
        for player in players:
            if player.pc <= index <= player.pc + player.size:
                pygame.draw.rect(screen, player_colors[player.number - 1], [x, y, element_size, element_size])
                current_text_color = highlighted_text_color
                busy = 1

    if not busy:
        pygame.draw.rect(screen, element_color, [x, y, element_size, element_size])

    # text = font.render(format(step.field[index] & 240, '02x')[0].upper(), True, current_text_color)
    # screen.blit(text, (x + 1, y + 3))
    # text = font.render(format(step.field[index] & 15, '02x')[1].upper(), True, current_text_color)
    # screen.blit(text, (x + 9, y + 3))

    # text = font.render(memory[index].encode('hex').upper(), True, current_text_color)
    # screen.blit(text, (x + 1, y  + 3))

    value = format(step.field[index], '02x').upper()
    text = font.render(value, True, current_text_color)
    screen.blit(text, (x + 1, y + 2))


def draw_map(steps, players):
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

    iteration = 0
    run = 1
    loop = True
    while loop:

        pygame.draw.rect(screen, background_color, [width - menu_width, 0, menu_width, height])
        iteration_number = info_font.render(str(iteration), True, text_color)
        screen.blit(iteration_number, (width - 180, 100))

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
            for i in range(64):
                for j in range(64):
                    render(i, j, index, screen, font, steps[iteration], players)
                    index += 1

        if run < 0:
            iteration += 1
        pygame.display.update()

    pygame.quit()
    quit()
