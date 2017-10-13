from __future__ import print_function
import numpy as np
from collections import deque
import struct
from classes import Player, Step, Carriage, bin_to_int


def parse_players(file):

    number_of_players = struct.unpack('B', file.read(1))[0]
    # number_of_players = int.from_bytes(file.read(1), byteorder='big')
    # number_of_players = int(file.read(1))
    # number_of_players = data[index]

    players = []
    for i in range(number_of_players):
        player = Player(struct.unpack('B', file.read(1))[0])
        #player = Player(data[index])

        player.pc = file.read(4)
        # player.pc = data[index: index + 4]

        player.set_size(file.read(4))
        # player.set_size(data[index: index + 4])

        # player.set_name(struct.unpack('s', data)[0])
        player.set_name(file.read(129))
        # player.set_name(data[index: index + 129])

        player.set_comment(file.read(2049))
        # player.set_comment(data[index: index + 2049])

        players.append(player)

    return players, number_of_players


def parse_step(file, index):
    step = Step()

    file.seek(index, 1)
    step.field = file.read(4097)
    # step.field = data[index: index + 4097]
    index += 4097

    file.seek(index, 1)
    number_of_carriages = bin_to_int(file.read(4))
    # number_of_carriages = bin_to_int(data[index: index + 4])
    index += 4

    while number_of_carriages > 0:
        carriage = Carriage()

        file.seek(index, 1)
        carriage.player_number = file.read(1)
        #carriage.player_number = data[index]
        index += 1

        file.seek(index, 1)
        carriage.pc = file.read(4)
        # carriage.pc = data[index: index + 4]
        index += 4

        file.seek(index, 1)
        carriage.is_change = file.read(1)
        # carriage.is_change = data[index]
        index += 1

        file.seek(index, 1)
        carriage.set_change(file.read(4))
        # carriage.set_change(data[index: index + 4])
        index += 4

        step.carriages.append(carriage)
        number_of_carriages -= 1

    return step, index


def parse_step_size(file, index):
    index += 4097

    file.seek(index, 1)
    number_of_carriages = bin_to_int(file.read(4))
    # number_of_carriages = bin_to_int(data[index: index + 4])
    file.seek(-8, 1)
    index += 4

    index += (number_of_carriages * 10)

    return index


def parse(file, file_size):
    players, number_of_players = parse_players(file)

    # steps = deque()
    indexes = list()
    index = 0
    indexes.append(index)
    while index < file_size:
        # step, index = parse_step(data, index)
        # steps.append(step)
        index = parse_step_size(file, index)
        indexes.append(index)

    print()
    print(index)
    print(file_size)
    return players, indexes
