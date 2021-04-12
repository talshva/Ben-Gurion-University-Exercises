import math
''' Given an Integer, positive number as an input, the output is a tuple of 2 prime numbers 'a' and 'b' that hold: number = a+b '''

def goldbach_pair(n: int) -> tuple[int, int]:
    if n > 2:
        for i in range(1, n):
            if is_prime(i) and is_prime(n - i):
                return i, n - i
    else:
        return 0, 0


def is_prime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if not x % i:
            return 0
    return 1


x = int(input("Enter a number: \n"))
print(goldbach_pair(x))
