import numpy as np
from PIL import Image


def ft_load(path: str) -> np.array:
    """open an image and transforme en tableau 2d"""
    try:
        image = Image.open(path)
    except IOError:
        raise IOError("image open error")
    except Exception as e:
        print(f"error {e}")
        return
    arr = np.array(image)
    print(f"The shape of image is: {arr.shape}")
    print(arr)
    return arr


def main():
    return 0


if __name__ == '__main__':
    main()
