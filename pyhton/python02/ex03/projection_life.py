import matplotlib.pyplot as plt
import pandas as pd
from load_csv import load


def ft_aff_pop(dataa: pd.DataFrame, dat: pd.DataFrame):
    """create a graph"""
    # on prend que les colonnes country et 1900
    dataa_country = dataa[["country", "1900"]]
    dat_pib = dat[["country", "1900"]]
    #  on merge les deux dataframes en se basant sur la colonne
    #  country pour faire correspondre les pays
    #  suffixe permet de renommer les colonne country
    #  et 1900 pour éviter les conflits
    #  ce qui crée un dataframe avec 3 colone
    #  country, 1900pays, 1900pib
    mergeed = pd.merge(dataa_country, dat_pib, on="country",
                       suffixes=("pays", "pib"))
    """  .pd.to_numeric(...) convertit la colonne
        en type numérique (float/int).
         .errors="coerce" : si une valeur n’est pas convertible
    (ex. "n/a" ou "10M"), elle devient NaN (valeur manquante)."""
    mergeed["1900pays"] = pd.to_numeric(mergeed["1900pays"], errors="coerce")
    mergeed["1900pib"] = pd.to_numeric(mergeed["1900pib"], errors="coerce")
    # suppression de toutes les lignes vides
    mergeed = mergeed.dropna()
#    print(mergeed)
    plt.figure(figsize=(12, 10))
    plt.scatter(mergeed["1900pib"], mergeed["1900pays"])
    plt.title("1900")
    plt.xlabel("Gross domestic product")
    plt.ylabel("Life Expectancy")
#    plt.axis([0, 10000, 18, 55])
    plt.ylim(18, 55)
    plt.xscale("log")
    plt.xlim(300, 10000)
#    ax = plt.gca()
#    plt.savefig("projection_life.png")
    plt.show()
    return


def main():
    dataa = load("../ex01/life_expectancy_years.csv")
    dat = load("../income_per_person_gdppercapita_ppp_inflation_adjusted.csv")
    ft_aff_pop(dataa, dat)
    return


if __name__ == '__main__':
    main()
