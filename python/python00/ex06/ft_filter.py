import sys


def ft_filter(function, iterable):
    """fonction filter, return iterable"""
    if function is None:
        return (item for item in iterable if item)
    else:
        return (item for item in iterable if function(item))


def main() -> int:
    listt = ["hello", "world"]
    listee = list(ft_filter(None, listt))
    # conversion de l iterateur en une liste
    print(listee)
    return 0


if __name__ == '__main__':
    sys.exit(main())
