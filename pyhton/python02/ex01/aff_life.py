import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from load_csv import load


def ft_aff_life(dataa: pd.DataFrame):
    """create a graph"""
#    dataa_country = dataa[dataa["country"] == "france"].squeeze()
    dataa_country = dataa[dataa["country"] == "France"].squeeze()
#    print(dataa_country)

    years = dataa_country.index[1:].astype(int)
    values = dataa_country.values[1:]
#    print(years)
    plt.figure(figsize=(10, 6))
    plt.plot(np.array(years), np.array(values), label="France")
    plt.title("France Life expectancy Projections")
    plt.xlabel("Year")
    plt.ylabel("Life expectancy")
    plt.grid(False)
    plt.gca().set_xticks(years[::40])
    plt.show()
    return


def main():
    dataa = load("life_expectancy_years.csv")
    ft_aff_life(dataa)
    return


if __name__ == '__main__':
    main()
