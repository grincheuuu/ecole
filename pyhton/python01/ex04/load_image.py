import numpy as np
from PIL import Image
from rotate import ft_rotate


def ft_cut_part_image(array: np.array, size: int) -> np.array:
    """zoom image"""
    try:
        assert array is not None
    except AssertionError:
        print("array null, zoom impossible")
        exit(1)
    except Exception as e:
        print(f"error {e}")
        return
    x = array.shape[0]
    y = array.shape[1]
    debut_x = int((x + 500) / 2 - size / 2)
    debut_y = int((y - 400) / 2 - size / 2)
    new_arr = array[debut_y:debut_y + size, debut_x:debut_x + size]
    gray = (
        0.299 * new_arr[:, :, 0] +
        0.587 * new_arr[:, :, 1] +
        0.114 * new_arr[:, :, 2]
    ).astype(np.uint8)
    if gray.ndim == 2:  # si c'est une image 2D (400,400)
        temp = gray.shape
        gray = np.expand_dims(gray, axis=2)  # on obtient (400,400,1)
    print(f"The shape of image is:{gray.shape} or {temp}")
#    plt.imshow(gray, cmap='gray')
#    plt.show()
    return gray


def ft_load(path: str) -> np.array:
    """open an image and transforme en tableau 2d"""
    try:
        image = Image.open(path)
    except IOError as e:
        print(f"image open error: {e}")
        return
    arr = np.array(image)
    return arr


def main():
    array = ft_load("animal.jpeg")
    arr_trunc = ft_cut_part_image(array, 400)
    print(arr_trunc)
    print(ft_rotate(arr_trunc))
    return 0


if __name__ == '__main__':
    main()
