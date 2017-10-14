from __future__ import print_function
import numpy as np
from collections import deque
import struct
from classes import Player, Step, Carriage, bin_to_int


def parse_players(file, index):
    file.seek(index)
    number_of_players = struct.unpack('B', file.read(1))[0]
    # number_of_players = int.from_bytes(file.read(1), byteorder='big')
    # number_of_players = int(file.read(1))
    # number_of_players = data[index]
    index += 1

    players = []
    for i in range(number_of_players):
        file.seek(index)
        player = Player(struct.unpack('B', file.read(1))[0])
        # player = Player(data[index])
        index += 1

        file.seek(index)
        player.pc = file.read(4)
        # player.pc = data[index: index + 4]
        index += 4

        file.seek(index)
        player.set_size(file.read(4))
        # player.set_size(data[index: index + 4])
        index += 4

        file.seek(index)
        # player.set_name(struct.unpack('s', data)[0])
        player.set_name(file.read(129))
        # player.set_name(data[index: index + 129])
        index += 129

        file.seek(index)
        player.set_comment(file.read(2049))
        # player.set_comment(data[index: index + 2049])
        index += 2049

        players.append(player)

    # index += (number_of_players * 2181)

    return players, index


def parse_step(file, index):
    step = Step()

    file.seek(index)
    step.field = bytearray(file.read(4097))
    # step.field = data[index: index + 4097]
    # index += 4097

    # file.seek(index, 1)
    number_of_carriages = bin_to_int(file.read(4))
    # number_of_carriages = bin_to_int(data[index: index + 4])
    # index += 4

    for i in range(number_of_carriages):
        carriage = Carriage()

        # .seek(index, 1)
        carriage.player_number = struct.unpack('B', file.read(1))[0]
        # carriage.player_number = data[index]
        # index += 1

        # file.seek(index, 1)
        carriage.pc = file.read(4)
        # carriage.pc = data[index: index + 4]
        # index += 4

        # file.seek(index, 1)
        carriage.is_change = struct.unpack('B', file.read(1))[0]
        # carriage.is_change = data[index]
        # index += 1

        # file.seek(index, 1)
        carriage.set_change(file.read(4))
        # carriage.set_change(data[index: index + 4])
        # index += 4

        step.carriages.append(carriage)

    return step


def parse_step_size(file, index):
    index += 4097

    file.seek(index)
    number_of_carriages = bin_to_int(file.read(4))
    # number_of_carriages = bin_to_int(data[index: index + 4])
    # file.seek(-4, 1)
    index += 4

    index += (number_of_carriages * 10)

    return index


def parse(file, file_size):
    index = 0
    players, index = parse_players(file, index)

    # steps = deque()
    indexes = list()
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
