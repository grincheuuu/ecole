class calculator:
    """do somme calcul"""
    def __init__(self, vecteur1, vecteur2):
        """calculator construteur"""
        self.vecteur1 = vecteur1
        self.vecteur2 = vecteur2

    @staticmethod
    def dotproduct(V1: list[float], V2: list[float]) -> None:
        """multiplie les elemenst de chaque list et additionne le tout"""
        total = 0
        for i in range(len(V1)):
            total += V1[i] * V2[i]
        print(f"Dot product is: {total}")

    @staticmethod
    def add_vec(V1: list[float], V2: list[float]) -> None:
        """addtionne les elements de chaques listes"""
        total = []
        for i in range(len(V1)):
            total.append(float(V1[i]) + float(V2[i]))
        print(f"Add Vector is : {total}")

    @staticmethod
    def sous_vec(V1: list[float], V2: list[float]) -> None:
        """sous les elements de la liste2 a la liste1"""
        total = []
        for i in range(len(V1)):
            total.append(float(V1[i]) - float(V2[i]))
        print(f"Sous Vector is: {total}")


def main():
    return 0


if __name__ == '__main__':
    main()
