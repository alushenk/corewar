import binascii


def bin_to_int(data):
    return int(binascii.hexlify(data), 16)


def bin_to_str(data):
    return data.decode('utf-8')


def set_number(data):
    if data > 127:
        data -= 0x100
    return data


class Carriage(object):
    __slots__ = ['_player_number', '_pc']

    def __init__(self):
        self._player_number = 0
        self._pc = 0

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


class Step(object):
    __slots__ = ['carriages', 'field']

    def __init__(self):
        self.carriages = []


class Player(object):
    def __init__(self, player_number):
        self.number = set_number(player_number)
        self.size = 0
        self.pc = 0
        self.name = 0
        self.comment = 0

    def set_size(self, data):
        self.size = bin_to_int(data)

    def set_name(self, data):
        self.name = bin_to_str(data)

    def set_comment(self, data):
        self.comment = bin_to_str(data)


class Data(object):
    def __init__(self):
        self.number_of_players = 0
        self.players = []
