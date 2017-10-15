from __future__ import print_function
import struct
from classes import Player, Step, Carriage, bin_to_int


def parse_players(file, index):
    file.seek(index)
    number_of_players = struct.unpack('B', file.read(1))[0]
    index += 1

    players = []
    for i in range(number_of_players):
        file.seek(index)
        player = Player(struct.unpack('B', file.read(1))[0])
        index += 1

        file.seek(index)
        player.pc = file.read(4)
        index += 4

        file.seek(index)
        player.set_size(file.read(4))
        index += 4

        file.seek(index)
        player.set_name(file.read(129))
        index += 129

        file.seek(index)
        player.set_comment(file.read(2049))
        index += 2049

        players.append(player)

    return players, index


def parse_step(file, index):
    step = Step()

    file.seek(index)
    step.field = bytearray(file.read(4097))

    number_of_carriages = bin_to_int(file.read(4))

    for i in range(number_of_carriages):
        carriage = Carriage()

        carriage.player_number = struct.unpack('B', file.read(1))[0]
        carriage.pc = file.read(4)
        carriage.is_change = struct.unpack('B', file.read(1))[0]
        carriage.set_change(file.read(4))
        carriage.set_last_live(file.read(4))
        carriage.set_lives(file.read(4))

        step.carriages.append(carriage)

    return step


def parse_step_size(file, index):
    index += 4097

    file.seek(index)
    number_of_carriages = bin_to_int(file.read(4))
    index += 4

    index += (number_of_carriages * 18)

    return index


def parse(file, file_size):
    index = 0
    players, index = parse_players(file, index)

    indexes = list()
    while index < file_size:
        indexes.append(index)
        index = parse_step_size(file, index)

    print(index)
    print(file_size)
    return players, indexes
