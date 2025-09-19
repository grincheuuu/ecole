import numpy as np


def slice_me(family: list, start: int, end: int) -> list:
    """verify une liste de listes et renvoie une liste tronquer"""
    if not isinstance(family, list):
        raise AssertionError("Bad argument")
    if not isinstance(start, int) or not isinstance(end, int):
        raise AssertionError("Bad argument")
    for x in family:
        if not isinstance(x, list):
            raise AssertionError("Bad argument")
    y = len(family[0])
    for le in family:
        if y is not len(le):
            raise AssertionError("Bad argument")
    if start < 0 or end > (len(family) - 1):
        raise AssertionError("Bad argument")
#    print(f"My shape is : ({len(family)}, {y})")
    arr = np.array(family)
    print(f"My shape is : {arr.shape}")
    new_arr = arr[start:end]
    print(f"My new shape is : {new_arr.shape}")
    return new_arr.tolist()


def main() -> int:
    return 0


if __name__ == 'main':
    main()
