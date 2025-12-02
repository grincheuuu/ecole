def square(x: int | float) -> int | float:
    """return le carre"""
    return x * x


def pow(x: int | float) -> int | float:
    """return l'expodentiel du nombre par le nombre"""
    return x**x


def outer(x: int | float, function) -> object:
    """utilise la closure"""
    try:
        assert x is not None and function is not None, "parameters obligatoir"
        assert type(x) is int or type(x) is float, "x must be int or float"
    except AssertionError as e:
        raise AssertionError({e})
    count = x
    # non local est pour dire a python d'utiliser
    #  count de fonction englobante outer
    # non local a la fonction inner

    def inner() -> float:
        nonlocal count
        count = function(count)
        return count
    return inner


def main():
    return 0


if __name__ == '__main__':
    main()

"""Ce n’est pas l’exemple le plus utile, mais on pourrait imaginer
une fonction plus complexe à la place de l’addition, dont la mise
 en cache du résultat serait nécessaire.
L’idée ici est que notre fonction cached_addition retourne à chaque
 appel une nouvelle fonction addition créée dynamiquement, utilisant
   un cache particulier. Ce cache est une variable définie localement
     dans cached_addition et donc accessible depuis addition.

Cependant, une fois l’appel à cached_addition terminé, son scope
 local est détruit, ce qui doit impliquer la destruction des valeurs
   qu’il contient. Ici, on voit bien que cache lui survit puisqu’il
   continue à être utilisé sans problème par la fonction addition.

Ce qu’il se passe c’est que la fonction addition crée une closure
qui emprisonne les variables locales des scopes parents qu’elle utilise.
 Cela permet à ces valeurs d’être toujours référencées.
 On peut d’ailleurs constater que notre fonction addition
 possède un attribut spécial __closure__.
>>> def cached_addition():
...     cache = {}
...     def addition(x, y):
...         if (x, y) not in cache:
...             print(f'Computing {x} + {y}')
...             cache[x, y] = x + y
...         return cache[x, y]
...     return addition
...
>>> addition = cached_addition()
>>> addition(1, 2)
Computing 1 + 2
3
>>> addition(1, 2)
3
>>> addition(2, 3)
Computing 2 + 3"""
