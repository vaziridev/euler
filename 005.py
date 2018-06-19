#ProjectEuler: Problem 5
#Find the smallest positive number evenly divisible by all #s from 1 to 20
import time
from functools import reduce

def main():
    start = time.time()
    result = lcm1To20(range(1,21))
    elapsed = time.time() - start
    print("%s found in %s seconds" % (result, elapsed))

def gcd(a, b):
    #Note: can be improved by using tuples, so learn those
    while b:
        temp = b
        b = a % b
        a = temp
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcm1To20(iterable):
    return reduce(lcm, iterable)

main()
