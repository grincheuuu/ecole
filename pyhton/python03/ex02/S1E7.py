from S1E9 import Character


class Baratheon(Character):
    """Representing the Baratheon family."""
    def __init__(self, name, alive: bool = True):
        """constructor Baratheon"""
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
    def __init__(self, name, alive: bool = True):
        """constructor Lannister"""
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

    def __repr__(self):
        """methode repr"""
        return self.__str__()

    @classmethod
    def create_lannister(cls, namee, aliveee: bool = True):
        """create new object of class"""
        return (cls(namee, aliveee))
