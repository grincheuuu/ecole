from abc import ABC, abstractmethod


class Character(ABC):
    """creating absctract class character"""
    def __init__(self, name, alive: bool = True):
        """character constructeur"""
        self.first_name = name
        self.is_alive = alive

    @abstractmethod
    def die(self):
        """die method parent"""
        pass


class Stark(Character):
    """creating personnage classe qui herite de character"""
    def __init__(self, name=None, is_alive: bool = True):
        """constructor called"""
        if name is None or name == "":
            raise ValueError("A Stark must have a name")
        self.first_name = name
        self.is_alive = is_alive

    def die(self):
        """method child"""
        self.is_alive = False
