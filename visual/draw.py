import pygame

# colors
background_color = (39, 40, 34)
element_color = (70, 70, 70)
text_color = (180, 180, 180)
player_color = (0, 255, 0)
highlighted_text_color = (0, 0, 0)

# sizes
space = 1
element_size = 16
menu_width = 200
height = (element_size + space) * 64
width = height + menu_width

# temporary defines
player_start_index = 1
size = 12

# font
# font_name = "raleway/Raleway-Thin.ttf"
font_name = "quicksand/Quicksand-Light.ttf"
font_size = element_size + 2


def render(i, j, index, screen, font, step):
    x = j * (element_size + space)
    y = i * (element_size + space)
    if player_start_index <= index <= player_start_index + size:
        current_text_color = highlighted_text_color
        current_player_color = player_color
    else:
        current_text_color = text_color
        current_player_color = element_color

    pygame.draw.rect(screen, current_player_color, [x, y, element_size, element_size])

    # text = font.render(format(step.field[index] & 240, '02x')[0].upper(), True, current_text_color)
    # screen.blit(text, (x + 1, y + 3))
    # text = font.render(format(step.field[index] & 15, '02x')[1].upper(), True, current_text_color)
    # screen.blit(text, (x + 9, y + 3))

    # text = font.render(memory[index].encode('hex').upper(), True, current_text_color)
    # screen.blit(text, (x + 1, y  + 3))

    value = format(step.field[index], '02x').upper()
    text = font.render(value, True, current_text_color)
    screen.blit(text, (x + 1, y + 2))


def draw_map(steps):
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
                    render(i, j, index, screen, font, steps[iteration])
                    index += 1

        if run < 0:
            iteration += 1
        pygame.display.update()

    pygame.quit()
    quit()
