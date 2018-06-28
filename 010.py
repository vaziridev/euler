#ProjectEuler: Problem 10
#Find the sum of all primes below two million.
import math
import time

def main():
    sumPrime = 2
    start = time.time()
    for i in range(3, 2000000, 2):
        if isPrime(i):
            sumPrime += i
    elapsed = time.time() - start
    print("Sum of primes < 2000000 = %s. Found in %s seconds." % (sumPrime, elapsed))

def isPrime(n):
    n = abs(n)
    if n % 2 == 0 and n > 2:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

main()
