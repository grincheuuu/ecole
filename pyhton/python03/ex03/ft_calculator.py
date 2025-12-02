class calculator:
    """do somme calcul"""
    def __init__(self, vecteur, operateur="+", nb: int = "0"):
        """calculator constructeur"""
        self.vecteur = vecteur
        self.operateur = operateur
        self.nb = nb

    def __add__(self, object) -> None:
        """addtionne l'object fournie a chaque element de la liste"""
        result = []
        for x in self.vecteur:
            x += object
            result.append(x)
        self.vecteur = result
        print(self.vecteur)

    def __mul__(self, object) -> None:
        """multiple l'object fournie a chaque element de la liste"""
        result = []
        for x in self.vecteur:
            x *= object
            result.append(x)
        self.vecteur = result
        print(self.vecteur)

    def __sub__(self, object) -> None:
        """soustrait l'object fournie a chaque element de la liste"""
        result = [x - object for x in self.vecteur]
        self.vecteur = result
        print(self.vecteur)

    def __truediv__(self, object) -> None:
        """divise l'object fournie a chaque element de la liste"""
        if object == 0:
            raise ZeroDivisionError("erreur division par 0")
        result = [x / object for x in self.vecteur]
        self.vecteur = result
        print(self.vecteur)


def main():
    return 0


if __name__ == '__main__':
    main()
