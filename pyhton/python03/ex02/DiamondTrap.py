from S1E7 import Baratheon, Lannister


class King(Baratheon, Lannister):
    """class king"""
    def __init__(self, name=None, alive: bool = True,
                 eyes="brown", hairs="dark"):
        """constructor king"""
        if name is None or name == "":
            raise ValueError("king must have a name")
        self.first_name = name
        self.is_alive = alive
        self.family_name = "Baratheon"
        self._eyes = eyes
        self._hairs = hairs

    def get_eyes(self):
        """fournie la couleur des yeux"""
        return self._eyes

    def set_eyes(self, color):
        """change la couleur des yeux"""
        self._eyes = color

    def get_hairs(self):
        """fournie la couleur des cheveux"""
        return self._hairs

    def set_hairs(self, color):
        """change la couleur des cheveux"""
        self._hairs = color


"""
    @property
    def get_eyes(self):
        return self._eyes

    @get_eyes.setter
    def set_eyes(self, color):
        self._eyes = color

    @property
    def get_hairs(self):
        return self._hairs

    @get_hairs.setter
    def set_hairs(self, color):
        self._hairs = color
        """


def main():
    return 0


if __name__ == '__main__':
    main()
