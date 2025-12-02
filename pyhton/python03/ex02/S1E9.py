from abc import ABC, abstractmethod


class Character(ABC):
    """creating absctract class character"""
    def __init__(self, name, alive: bool = True):
        """character constructeur"""
        try:
            name is not None
        except TypeError:
            print("TypeError: Can't instantiate abstract"
                  " class Character with abstract method")
            raise
        self.first_name = name
        self.is_alive = alive

    @abstractmethod
    def die(self):
        """die method parent"""
        pass


class Stark(Character):
    """creating personnage classe qui herite de character"""
    def __init__(self, name, is_alive: bool = True):
        """constructor called"""
        self.first_name = name
        self.is_alive = is_alive

    def die(self):
        """method child"""
        self.is_alive = False
