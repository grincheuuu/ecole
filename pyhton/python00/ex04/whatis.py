import sys

if len(sys.argv) == 1:
    sys.exit()

try:
    n = int(sys.argv[1])
except ValueError:
    print("AssertionError: argument is not an integer")

if len(sys.argv) != 2:
    print("AssertionError: more than one argument is provided")
    sys.exit(1)


n = int(sys.argv[1])
if n >= 0:
    print("I'm Even.")
else:
    print("I'm Odd.")


'''
try:
    assert int(sys.argv[1]), # echec avec 0 car assert recois false
    assert len(sys.argv) != 2, "the arguments are bad"
    except AssertionError as e:
    print(f"AssertionError {e}")
    except ValueError as e:
    raise AssertionError
'''
