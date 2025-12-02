import numpy as np
import matplotlib.pyplot as plt


def ft_rotate(array: np.array) -> np.array:
    """rotate image"""
    try:
        assert array is not None, "AssertionError: tableau a transposer null"
    except AssertionError as e:
        print(e)
        exit(1)
    if array.ndim == 3:  # ex : (400,400,1)
        array = array[:, :, 0]
# on enlève la 3ᵉ dim pour manipuler plus simplement
    lengh_x = array.shape[0]
    lengh_y = array.shape[1]
    tab = []
    for y in range(lengh_y):
        listee = []
        for x in range(lengh_x):
            listee.append(array[x][y])
        tab.append(listee)
    arr = np.array(tab)
    print(f"New shape after Transpose:{arr.shape}")
    print(arr)
    plt.imshow(arr, cmap='gray')
    plt.show()
    return arr
