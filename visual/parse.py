from __future__ import print_function
import numpy as np
from collections import deque
from classes import Player, Step, Carriage, bin_to_int


def parse_players(data):
    index = 0

    number_of_players = data[index]
    index += 1

    players = []
    while number_of_players > 0:
        player = Player(data[index])
        index += 1

        player.pc = data[index: index + 4]
        index += 4

        player.set_size(data[index: index + 4])
        index += 4

        player.set_name(data[index: index + 129])
        index += 129

        player.set_comment(data[index: index + 2049])
        index += 2049

        players.append(player)
        number_of_players -= 1

    return players, number_of_players, index


def parse_step(data, index):
    step = Step()

    step.field = data[index: index + 4097]
    index += 4097

    number_of_carriages = bin_to_int(data[index: index + 4])
    index += 4

    while number_of_carriages > 0:
        carriage = Carriage()

        carriage.player_number = data[index]
        index += 1

        carriage.pc = data[index: index + 4]
        index += 4

        carriage.is_change = data[index]
        index += 1

        carriage.addr_of_change[index] = data[index]
        index += 1
        carriage.addr_of_change[index] = data[index]
        index += 1
        carriage.addr_of_change[index] = data[index]
        index += 1
        carriage.addr_of_change[index] = data[index]
        index += 1

        step.carriages.append(carriage)
        number_of_carriages -= 1

    return step, index


def parse(data):
    data_size = len(data)

    players, number_of_players, index = parse_players(data)

    steps = deque()
    while index < data_size:
        step, index = parse_step(data, index)
        steps.append(step)

    print()
    print(index)
    print(data_size)
    return steps, players
