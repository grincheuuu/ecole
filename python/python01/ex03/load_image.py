import numpy as np
from zoom import ft_load_zoom
from PIL import Image


def ft_load(path: str) -> np.array:
    """open an image and transforme en tableau 2d"""
    try:
        image = Image.open(path)
    except IOError as e:
        print(f"image open error: {e}")
        return
    except Exception as e:
        print(f"error {e}")
        return
    arr = np.array(image)
    print(f"The shape of image is: {arr.shape}")
    return arr


def main():
    array = ft_load("animal.jpeg")
    print(array)
    print(ft_load_zoom(array, 400))
    return


if __name__ == '__main__':
    main()
