import random
import string
from dataclasses import dataclass, field


def generate_id() -> str:
    return "".join(random.choices(string.ascii_lowercase, k=15))


@dataclass
class Student:
    name: str
    surname: str
    active: bool = True
    login: str = field(default=None)
    id: str = field(default=None)

    def __post_init__(self):
        if self.login is not None:
            print("typeError: Student.__init__() got an "
                  "unexpected keyword argument 'login'")
        if self.id is not None:
            print("typeError: Student.__init__() got an"
                  " unexpected keyword argument 'id'")
        self.login = self.name[0] + self.surname[:]
        self.id = generate_id()


def main():
    return 0


if __name__ == '__main__':
    main()
