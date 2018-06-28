#ProjectEuler: Problem 3
#Find the largest prime factor of the number 600851475143
import math
import time

def main():
    limit = 600851475143
    start = time.time()
    #Using range instead of xrange has slowed this down by ~2x. Can be improved.
    for num in range(2,limit):
        if limit % num == 0:
            factor = limit / num
            if isPrime(factor):
                elapsed = time.time() - start
                print("Largest prime factor %s found in %s seconds." % (factor, elapsed))
                return

def isPrime(n):
    n = abs(n)
    if n % 2 == 0 and n > 2:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

main()
