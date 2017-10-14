import binascii
import numpy


def bin_to_int(data):
    return int(binascii.hexlify(data), 16)


def bin_to_str(data):
    # data = bytearray(data)
    return data.decode('utf-8').rstrip('\0')
    # return data.decode('unicode_escape').encode('utf-8')
    # return data


def set_number(data):
    if data > 127:
        data -= 0x100
    return data


class Carriage(object):
    __slots__ = ['_player_number', '_pc', '_is_change', 'addr_of_change']

    def __init__(self):
        self._player_number = 0
        self._pc = 0
        self._is_change = 0
        self.addr_of_change = 0

    @property
    def player_number(self):
        return self._player_number

    @player_number.setter
    def player_number(self, data):
        self._player_number = set_number(data)

    @property
    def pc(self):
        return self._pc

    @pc.setter
    def pc(self, data):
        self._pc = bin_to_int(data)

    @property
    def is_change(self):
        return self._is_change

    @is_change.setter
    def is_change(self, data):
        self._is_change = set_number(data)

    def set_change(self, data):
        addr_of_change = bin_to_int(data)
        self.addr_of_change = [addr_of_change + x for x in range(4)]


class Step(object):
    __slots__ = ['carriages', 'field', 'objects']

    def __init__(self):
        self.carriages = []
        self.objects = numpy.empty(4096, dtype=object)


class Player(object):
    def __init__(self, player_number):
        self.number = set_number(player_number)
        self.size = 0
        self._pc = 0
        self.name = 0
        self.comment = 0

    def set_size(self, data):
        self.size = bin_to_int(data)

    def set_name(self, data):
        self.name = bin_to_str(data)

    def set_comment(self, data):
        self.comment = bin_to_str(data)

    @property
    def pc(self):
        return self._pc

    @pc.setter
    def pc(self, data):
        self._pc = bin_to_int(data)


class Data(object):
    def __init__(self):
        self.number_of_players = 0
        self.players = []
