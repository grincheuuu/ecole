import numpy as np
import matplotlib.pyplot as plt


def ft_load_zoom(array: np.array, size: int):
    """zoom image"""
    try:
        assert array is not None
    except AssertionError:
        print("array null, zoom impossible")
        return 1
    x = array.shape[0]
    y = array.shape[1]
    debut_x = int((x + 500) / 2 - size / 2)
    debut_y = int((y - 400) / 2 - size / 2)
    new_arr = array[debut_y:debut_y + size, debut_x:debut_x + size]
    # Gray = 0.299 * R + 0.587 * G + 0.114 * B
    gray = (
        0.299 * new_arr[:, :, 0] +
        0.587 * new_arr[:, :, 1] +
        0.114 * new_arr[:, :, 2]
    ).astype(np.uint8)
    if gray.ndim == 2:  # si c'est une image 2D (400,400)
        temp = gray.shape
        gray = np.expand_dims(gray, axis=2)  # on obtient (400,400,1)
    print(f"New shape after slicing:{gray.shape} or {temp}")
    plt.imshow(gray, cmap='gray')
    plt.show()
    return gray
