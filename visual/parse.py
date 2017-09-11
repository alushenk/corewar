from __future__ import print_function
import numpy as np
import binascii


# int.from_bytes(b, byteorder='big', signed=False)
# binascii.hexlify(player_size) # returns 00000019 suka

# player_size = bytes(data[index: index + 4])
# print(int(player_size.encode('hex'), 16))

def parse(data):
    index = 0
    length = len(data)

    number_of_players = data[index]
    print(number_of_players)
    index += 1

    # dt = np.dtype([
    #     ('number_of_players', np.int8),
    #     ('num', np.int8),
    #     ('size', np.int16)])
    #
    # x = np.zeros((1,), dtype=dt)
    # print(np.fromfile(data, dtype=dt))

    while number_of_players > 0:
        player_number = data[index]
        print(player_number)
        index += 1

        player_size = data[index: index + 4]
        print(int(binascii.hexlify(player_size), 16))
        index += 4

        name = data[index: index + 129]
        print(name.decode('utf-8'))
        index += 129

        comment = data[index: index + 2049]
        print(comment.decode('utf-8'))
        index += 2049

        number_of_players -= 1

    map = data[index: index + 4097]
    print(map.decode('utf-8'))
    index += 4097

    number_of_carriages = data[index: index + 4]
    number_of_carriages = int(binascii.hexlify(number_of_carriages), 16)
    print(number_of_carriages)
    index += 4

    while number_of_carriages > 0:
        player_number = data[index]
        print(player_number)
        index += 1

        pc = data[index: index + 4]
        print(int(binascii.hexlify(pc), 16))
        index += 4

        number_of_carriages -= 1

    return map
