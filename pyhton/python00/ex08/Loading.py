# La fonction enumerate() ajoute un compteur à chaque élément d'une liste
#  ou de tout autre itérable, et renvoie une liste de tuples
#  contenant la position d'index et l'élément pour chaque élément
#  de l'itérable.
#  Il transforme l'itérable en quelque chose que nous pouvons
#  parcourir en utilisant des index, où chaque élément est accompagné
#  de son numéro (à partir de 0 par défaut).


def ft_tqdm(lst: range):
    """tqdm est un générateur qui : itère sur un iterable
    (ici souvent range(...)), à chaque itération il met à
    jour une barre de progression affichée sur la même ligne
    (grâce à \r), yield l’élément courant, pour que la boucle
    appelante puisse l’utiliser."""
    lengh = len(lst)
    bar_lengh = 50  # longueur constante de la barre d'affichage
    for i, elem in enumerate(lst, 1):
        pourcentage = i / lengh
        lengh_remplissage = int(bar_lengh * pourcentage)

        bar = "=" * (lengh_remplissage - 1) + ">"
        bar += " " * (bar_lengh - lengh_remplissage)
        print(f"\r{int(pourcentage*100):3d}%|[{bar}]| {i}/{lengh}",
              end="", flush=True)

# \r replace le curseur au début de la ligne, end=""
# n’ajoute pas de nouvelle ligne, flush=True force l’affichage immédiat.
        yield elem


def main():
    return 0


if __name__ == "__main__":
    main()
