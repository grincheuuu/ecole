import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from load_csv import load


def convert_value(values: str) -> float:
    if isinstance(values, str):
        values = values.strip()
        if values.endswith("M"):
            return float(values[:-1])


def ft_aff_pop(dataa: pd.DataFrame):
    """create a graph"""
    dataa_country = dataa[dataa["country"] == "France"].squeeze()
    dataa_deux = dataa[dataa["country"] == "Belgium"].squeeze()

    years = dataa_country.index[1:].astype(int)
    values = [convert_value(v) for v in dataa_country.values[1:]]
    values_deux = [convert_value(v) for v in dataa_deux.values[1:]]
    plt.figure(figsize=(12, 10))
    years = np.array(years)
    plt.plot(years, np.array(values_deux), label="Belgium", color="blue")
    plt.plot(years, np.array(values), label="France", color="green")
    plt.title("Population Projections")
    plt.xlabel("Year")
    plt.ylabel("Population")
    plt.legend()
    plt.grid(False)
    plt.xlim(1800, 2050)
    plt.gca().set_xticks(range(1800, 2051, 40))
    plt.gca().set_yticks(range(0, 100, 20))
    plt.show()
    return


def main():
    dataa = load("../population_total.csv")
    ft_aff_pop(dataa)
    return


if __name__ == '__main__':
    main()
