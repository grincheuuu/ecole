def NULL_not_found(object: any) -> int:
    if isinstance(object, type(None)):
        print(f"Nothing: {object} {type(object)}")
    elif isinstance(object, float):
        print(f"Cheese: {object} {type(object)}")
    elif isinstance(object, bool):
        print(f"Fake: {object} {type(object)}")
    elif isinstance(object, int):
        print(f"Zero: {object} {type(object)}")
    elif isinstance(object, str) and object == "":
        print(f"Empty: {type(object)}")
    else:
        print("Type not Found")
        return 1
    return 0


Nothing = None
Garlic = float("NaN")
Zero = 0
Empty = ''
Fake = False


NULL_not_found(Nothing)
NULL_not_found(Garlic)
NULL_not_found(Zero)
NULL_not_found(Empty)
NULL_not_found(Fake)
print(NULL_not_found("Brian"))
