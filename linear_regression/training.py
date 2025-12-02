import sys


def ft_try_open(path: str) -> dict:
    try:
        file = open(path)
    except Exception as e:
        print(f"open file error: {e}")
        return {'t0': 0, 't1': 0}
    liste = {}
    ligne = file.readlines()
    i = 0
    for t in ligne:
        if i == 0:
            liste['t0'] = float(t)
        else:
            liste['t1'] = float(t)
        i += 1
    return liste


def ft_try_input():
    print("veuillez entrer le kilometrage de la voiture svp:")
    km = input()
    try:
        mileage = float(km)
    except Exception as e:
        print(f"Not a valid Kilometrage: {e}")
        sys.exit(1)
    return mileage


def ft_linear():
    """linear regression"""
    result = ft_try_open("result.txt")
    kilometrage = ft_try_input()
    print(result)
    prix = result['t0'] + result['t1'] * kilometrage
    if prix < 0:
        prix = 0
    print(f"The estimated price for that mileage is: {int(prix)} euro")


def main() -> int:
    ft_linear()
    return (0)


if __name__ == '__main__':
    sys.exit(main())
