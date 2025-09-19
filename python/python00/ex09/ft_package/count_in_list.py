def count_in_list(lst, str) -> int:
    n = 0
    for x in lst:
        if x == str:
            n += 1
    return n
