import sys
import ft_filter


def ft_test_str(arg):
    """test alphanumeric characters"""
    for x in arg:
        if not x.isalnum() and x != " ":
            return False
    return True


def ft_test_arg():
    """parsing"""
    try:
        assert len(sys.argv) == 3, "the arguments are bad"
        assert ft_test_str(sys.argv[1]), "the arguments are bad"
        int(sys.argv[2]), "the arguments are bad"
    except (AssertionError, ValueError) as e:
        print(f"AssertionError: {e}")
        sys.exit(1)


def main() -> int:
    ft_test_arg()
    listee = sys.argv[1].split()
    print(list(ft_filter.ft_filter(
        lambda w: len(w) >= int(sys.argv[2]), listee)))  # car importer
    return (0)


if __name__ == '__main__':
    sys.exit(main())
