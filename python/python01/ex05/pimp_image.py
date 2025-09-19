import numpy as np
import matplotlib.pyplot as plt


def ft_error(array):
    try:
        assert array is not None
    except AssertionError:
        raise ("array null, impossible")


def ft_invert(array) -> np.array:
    """Inverts the color of the image received."""
    ft_error(array)
    new_array = np.copy(array)
    lengh_x = array.shape[1]
    lengh_y = array.shape[0]
    for y in range(lengh_y):
        for x in range(lengh_x):
            new_array[y][x][0] = 255 - new_array[y][x][0]  # r
            new_array[y][x][1] = 255 - new_array[y][x][1]  # v
            new_array[y][x][2] = 255 - new_array[y][x][2]  # b
    print(f"The shape of image is: {new_array.shape}")
    print(new_array)
    plt.imshow(new_array)
    plt.show()
    return new_array


def ft_red(array) -> np.array:
    """the color are more RED"""
    ft_error(array)
    new_array = np.copy(array)
    lengh_x = array.shape[1]
    lengh_y = array.shape[0]
    for y in range(lengh_y):
        for x in range(lengh_x):
            new_array[y][x][1] = 0  # v
            new_array[y][x][2] = 0  # b
    print(f"The shape of image is: {new_array.shape}")
    print(new_array)
    plt.imshow(new_array)
    plt.show()
    return new_array


def ft_green(array) -> np.array:
    """the color are more Green"""
    ft_error(array)
    new_array = np.copy(array)
    lengh_x = array.shape[1]
    lengh_y = array.shape[0]
    for y in range(lengh_y):
        for x in range(lengh_x):
            new_array[y][x][0] = 0  # r
            new_array[y][x][2] = 0  # b
    print(f"The shape of image is: {new_array.shape}")
    print(new_array)
    plt.imshow(new_array)
    plt.show()
    return new_array

    return


def ft_blue(array) -> np.array:
    """the color are more BLUE"""
    ft_error(array)
    new_array = np.copy(array)
    lengh_x = array.shape[1]
    lengh_y = array.shape[0]
    for y in range(lengh_y):
        for x in range(lengh_x):
            new_array[y][x][0] = 0  # r
            new_array[y][x][1] = 0  # v
    print(f"The shape of image is: {new_array.shape}")
    print(new_array)
    plt.imshow(new_array)
    plt.show()
    return new_array


def ft_grey(array) -> np.array:
    """the color are more GREY"""
    ft_error(array)
    #  moyenne sur les 3 canaux (axis=2 => combine R,G,B)
    gray = np.mean(array, axis=2).astype(np.uint8)
    if gray.ndim == 2:
        temp = gray.shape
        gray = np.expand_dims(gray, axis=2)
    print(f"The shape of image is:{gray.shape} or {temp}")
    plt.imshow(gray, cmap='gray')
    plt.show()
    return gray
