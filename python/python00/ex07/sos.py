import sys


def ft_test_arg(arg):
    """parsing parametre"""
    for x in arg:
        if not x.isalnum() and x != " ":
            return False
    return True


def ft_error():
    """parsing arg"""
    try:
        assert len(sys.argv) == 2, "the arguments are bad"
        assert ft_test_arg(sys.argv[1]), "the arguments are bad"
    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)


def ft_print_morse(strin):
    """impression code morse"""
    MORSE_CODE_DICT = {'A': '.-', 'B': '-...',
                       'C': '-.-.', 'D': '-..', 'E': '.',
                       'F': '..-.', 'G': '--.', 'H': '....',
                       'I': '..', 'J': '.---', 'K': '-.-',
                       'L': '.-..', 'M': '--', 'N': '-.',
                       'O': '---', 'P': '.--.', 'Q': '--.-',
                       'R': '.-.', 'S': '...', 'T': '-',
                       'U': '..-', 'V': '...-', 'W': '.--',
                       'X': '-..-', 'Y': '-.--', 'Z': '--..',
                       '1': '.----', '2': '..---', '3': '...--',
                       '4': '....-', '5': '.....', '6': '-....',
                       '7': '--...', '8': '---..', '9': '----.',
                       '0': '-----', ', ': '--..--', '.': '.-.-.-',
                       '?': '..--..', '/': '-..-.', '-': '-....-',
                       '(': '-.--.', ')': '-.--.-', " ": "/ "}
    st = ""
    for x in strin:
        if x.islower():
            st += MORSE_CODE_DICT[x.upper()] + " "
        else:
            st += MORSE_CODE_DICT[x] + " "
    print(st)


def main() -> int:
    ft_error()
    ft_print_morse(sys.argv[1])
    return (0)


if __name__ == '__main__':
    sys.exit(main())
