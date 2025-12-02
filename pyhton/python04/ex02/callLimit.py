from typing import Any


def callLimit(limit: int):
    """appel callLimiter"""
    count = 0

    def callLimiter(function):
        """appel limit_function"""

        def limit_function(*args: Any, **kwds: Any):
            """verifie si la function respecte la limite"""
            nonlocal count
            count += 1
            if count > limit:
                print(f"Error <function g at {function}> call too many times")
            else:
                function()
            return function
        limit_function(count, limit)
        return limit_function
    return callLimiter


def main():
    return 0


if __name__ == "__main__":
    main()
