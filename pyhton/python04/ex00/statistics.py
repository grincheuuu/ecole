def ft_statistics(*args: any, **kwargs: any) -> None:
    """do statistiques"""
    if kwargs is None or len(kwargs) == 0:
        print("ERROR")
        return
    for z, y in kwargs.items():
        if args is None or len(args) == 0:
            print("ERROR")
            continue
        nb_n = len(args)
        listee = list(args)
        total = 0
        for x in args:
            try:
                assert type(x) is float or type(x) is int
            except AssertionError:
                raise AssertionError("only number is use")
            total += float(x)
        listee = sorted(listee)
        moyenne = total / nb_n
        match y:
            case "mean":
                print(f"mean : {moyenne}")
                continue
            case "median":
                if nb_n % 2 == 0:
                    median = listee[nb_n // 2 - 1]
                # // division entiere arrondi vers
                #  le bas pour pas avoir de float
                else:
                    median = listee[nb_n // 2]
                print(f"median : {median}")
                continue
            case "quartile":
                quartile = []
                if nb_n % 4 == 0:
                    quartile.append(float(listee[nb_n // 4]))
                    quartile.append(float(listee[(nb_n * 3) / 4] - 1))
                else:
                    quartile.append(float(listee[int(nb_n // 4)]))
                    quartile.append(float(listee[int((nb_n * 3) / 4)]))
                print(f"quartile : {quartile}")
                continue
            case "std":
                somme_ecart_a_la_moyenne = 0
                for x in listee:
                    somme_ecart_a_la_moyenne += (x - moyenne) ** 2
                var = somme_ecart_a_la_moyenne / (nb_n)
                std = var ** 0.5
                print(f"std : {std}")
                continue
            case "var":
                somme_ecart_a_la_moyenne = 0
                for x in listee:
                    somme_ecart_a_la_moyenne += (x - moyenne) ** 2
                var = somme_ecart_a_la_moyenne / (nb_n)
                print(f"var : {var}")
                continue
            case _:
                break


def main():
    return 0


if __name__ == "__main__":
    main()
