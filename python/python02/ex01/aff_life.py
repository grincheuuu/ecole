import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from load_csv import load

def ft_aff_life(dataa: pd.DataFrame):
    """create a graph"""
    for x in dataa:
        print(x)
        print
    return

def main():
    dataa = load("life_expectancy_years.csv")
    ft_aff_life(dataa)
    return

if __name__ == '__main__':
    main()