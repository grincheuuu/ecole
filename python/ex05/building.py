import sys

def ft_parsing():
    """ma doc fonction parsing, gestion des erreurs"""
    if len(sys.argv) == 1 or sys.argv == "None":
        print("need a string as parameter")
        sys.exit(1)
    if len(sys.argv) > 2:
        print("AssertionError: bad number of argument")
        sys.exit(1)

#print(ft_parsing.__doc__)

def ft_print():
    """doc fonction"""
    print(f"The text contains {len(sys.argv[1])} characters:")
    up = 0
    low = 0
    space = 0
    nb = 0
    ponct = 0
    for x in sys.argv[1]:
        if x.isupper():
            up += 1
        elif x.islower():
            low += 1
        elif x.isspace():
            space += 1
        elif x.isnumeric():
            nb += 1
        else:
            ponct += 1
    print(f"{up} upper letters")
    print(f"{low} lower letters")
    print(f"{ponct} punctuation marks")
    print(f"{space} spaces")
    print(f"{nb} digits")

def main() -> int:
    ft_parsing()
    ft_print()
    return 0

if __name__ == '__main__':
    sys.exit(main())