#ProjectEuler: Problem 7
#Find the 10001st prime number
import math
import time

def main():
    i = 3
    count = 1
    start = time.time()
    while count < 10001:
        if isPrime(i):
            count += 1
            if count == 10001:
                break
        i += 2
    elapsed = time.time() - start
    print("Found 10001st prime %s in %s seconds" % (i, elapsed))

def isPrime(n):
    n = abs(n)
    if n == 1:
        return False
    if n % 2 == 0 and n > 2:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

main()
