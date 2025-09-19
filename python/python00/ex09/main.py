from ft_package import count_in_list


def main() -> int:
    print(count_in_list.count_in_list(["toto", "tata", "toto"], "toto"))
    print(count_in_list.count_in_list(["toto", "tata", "toto"], "tutu"))
    return (0)


if __name__ == '__main__':
    main()
