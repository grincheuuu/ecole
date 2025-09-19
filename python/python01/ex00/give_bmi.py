

def test_error(height: list[int | float], weight: list[int | float]):
    """parsing error"""
    v = type(height[0])
    w = type(weight[0])
    try:
        assert v == w, "different type"
        assert v is int or v is float, "bad type"
        assert len(height) == len(weight)
    except AssertionError as e:
        print(f"AssertionError: {e}")
        exit(1)
    for x in height:
        if type(x) is not v:
            raise AssertionError
    for z in weight:
        if type(z) is not w:
            raise AssertionError


def give_bmi(height: list[int | float],
             weight: list[int | float]) -> list[int | float]:
    """retourn l'imc"""
    test_error(height, weight)
    listee = []
    lengh = len(height)
    for i in range(lengh):
        imc = weight[i] / (height[i]**2)
        listee.append(imc)
    return listee


def apply_limit(bmi: list[int | float], limit: int) -> list[bool]:
    """apllique une limit a la liste bmi"""
    lis = []
    for x in bmi:
        if x < limit:
            lis.append("False")
        else:
            lis.append("True")
    return lis


def main() -> int:
    return 0


if __name__ == '__main__':
    main()
