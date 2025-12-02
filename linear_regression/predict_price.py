import sys
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

"""
def ft_calcul(t0: float, t1: float, file: pd.DataFrame,) -> (float, float):
    somme = 0.0
    somme2 = 0.0
    for row in file.itertuples():
        temp = ft_calcul_Estimate_Price(t0, t1, row.km / 1000.0)
          - row.price / 1000.0
        somme += temp
        somme2 += temp * (row.km / 1000.0)
    return somme, somme2

def ft_regression(file: pd.DataFrame):
    learningRate = 0.00001
    t0 = 0.0
    t1 = 0.0
    i = 0
    effectif = len(file)
    print(f"effectif {effectif}")
    while (i < 1000000):
        gradient = ft_calcul(t0, t1, file)
        tmp0 = learningRate * (1 / effectif) * gradient[0]
        tmp1 = learningRate * (1 / effectif) * gradient[1]
        t0 = t0 - tmp0
        t1 = t1 - tmp1
        print(f"tmp0 {tmp0}")
        print(f"tmp1 {tmp1}")
        i += 1
    t0 *= 1000.0
    print(f"t0 == {t0} t1 == {t1}")
"""


def ft_load_csv(path: str) -> pd.DataFrame:
    try:
        file = pd.read_csv(path)
    except FileNotFoundError:
        print("FileNotFoundError: the path is bad")
        sys.exit(1)
    except pd.errors.ParserError:
        print("ParserError: bad format")
        sys.exit(1)
    except PermissionError:
        print("PermissionError")
        sys.exit(1)
    except Exception as e:
        print(f"unexpcted open csv error: {e}")
        sys.exit(1)
    return file


def ft_calcul_Estimate_Price(t0: float, t1: float, km: float) -> float:
    return (t0 + t1 * km)


def ft_norm(limits: tuple, colonne: str, x: float) -> float:
    """NORMALISE"""
    if colonne == 'km':
        result_normalise = (x - limits[0]) / (limits[1] - limits[0])
    else:
        result_normalise = (x - limits[2]) / (limits[3] - limits[2])
    return result_normalise


def ft_calcul(t0: float, t1: float, file: pd.DataFrame,
              limits: tuple) -> (float, float):
    somme = 0.0
    somme2 = 0.0
    for row in file.itertuples():
        km_normalise = ft_norm(limits, 'km', row.km)
        prix_normalise = ft_norm(limits, "price", row.price)
        temp = ft_calcul_Estimate_Price(t0, t1, km_normalise) - prix_normalise
        somme += temp
        somme2 += temp * ft_norm(limits, 'km', row.km)
    return somme, somme2


def ft_limit(file: pd.DataFrame) -> tuple:
    min_km = file['km'].min()
    max_km = file['km'].max()
    min_price = file['price'].min()
    max_price = file['price'].max()
    limits = [min_km, max_km, min_price, max_price]
    return limits


def ft_graph(file: pd.DataFrame, t0: float, t1: float):
    x = np.linspace(0, 300000, 300000)
    y = t0 + t1 * x
    plt.plot(x, y, label="regression lineaire")
    plt.plot(file['km'], file['price'], "ob")
    plt.xlabel("kilometrage")
    plt.ylabel("prix")
    plt.legend()
    plt.show()
    return


def ft_regression(file: pd.DataFrame):
    learningRate = 0.01
    t0 = 0.0
    t1 = 0.0
    i = 0
    limits = ft_limit(file)
    effectif = len(file)
    print(f"effectif {effectif}")
    while (i < 10000):
        gradient = ft_calcul(t0, t1, file, limits)
        tmp0 = learningRate * (1 / effectif) * gradient[0]
        tmp1 = learningRate * (1 / effectif) * gradient[1]
        t0 = t0 - tmp0
        t1 = t1 - tmp1
        i += 1
    t1 = t1 * (limits[3] - limits[2]) / (limits[1] - limits[0])
    t0 = limits[2] + t0 * (limits[3] - limits[2]) - t1 * limits[0]
    fichier = open("result.txt", "w")
    t2 = str(t0) + "\n" + str(t1)
    ft_graph(file, t0, t1)
    ft_efficacite(file, t0, t1, effectif)
    fichier.write(t2)
    fichier.close()


def ft_efficacite(file: pd.DataFrame, t0: float, t1: float, effectif: int):
    somme_des_erreurs = 0
    variance_autour_moyenne = 0
    moyenne_valeur_reel = file.price.mean()
#    moyenne_valeur_reel = 1 / effectif * file.price.sum()   // identique
    for raw in file.itertuples():
        ecart = raw.price - (t1 * raw.km + t0)
        somme_des_erreurs += ecart * ecart
        variance_autour_moyenne += (raw.price - moyenne_valeur_reel) ** 2
    R2 = 1 - (somme_des_erreurs / variance_autour_moyenne)
    print(f"L'efficacite de l'algorithme de regression lineaire est de: {R2}")


def main():
    file_csv = ft_load_csv("data.csv")
    ft_regression(file_csv)
    return (0)


if __name__ == '__main__':
    sys.exit(main())
