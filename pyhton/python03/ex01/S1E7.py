from S1E9 import Character


class Baratheon(Character):
    """Representing the Baratheon family."""
    def __init__(self, name=None, alive: bool = True):
        """constructor Baratheon"""
        if name is None or name == "":
            raise ValueError("Baratheon must have a name")
        self.first_name = name
        self.is_alive = alive
        self.family_name = "Baratheon"
        self.eyes = "brown"
        self.hairs = "dark"

    def die(self):
        """method child"""
        self.is_alive = False

    def __str__(self):
        """methode str"""
        return f"Vector: ({self.family_name}, {self.eyes}, {self.hairs})"

    def __repr__(self):
        """methode repr"""
        return self.__str__()


class Lannister(Character):
    """Representing the Lannister family."""
    def __init__(self, name=None, alive: bool = True):
        """constructor Lannister"""
        if name is None or name == "":
            raise ValueError("Lannister must have a name")
        self.first_name = name
        self.is_alive = alive
        self.family_name = "Lannister"
        self.eyes = "blue"
        self.hairs = "light"

    def die(self):
        """method child"""
        self.is_alive = False

    def __str__(self):
        """methode str"""
        return f"Vector: ({self.family_name}, {self.eyes}, {self.hairs})"
# * `__repr__` est utilisé quand tu tapes juste le nom de
# l’objet dans un shell Python, ou quand tu appelles `repr(obj)`.

    def __repr__(self):
        """methode repr"""
        return self.__str__()

# @classmethod : → c’est un décorateur Python qui fait que la méthode
# reçoit la classe comme premier argument (par convention appelé cls),
#  et non pas l’instance (self).

    @classmethod
    def create_lannister(cls, namee, aliveee: bool = True):
        """create new object of class"""
        return (cls(namee, aliveee))


def main():
    return 0


if __name__ == '__main__':
    main()
