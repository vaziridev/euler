#ProjectEuler: Problem 2
#Find the sum of the even-valued terms whose values do not exceed 4 million
import time

def main():
    start = time.time()
    sum = findSum(4000000)
    elapsed = time.time() - start
    print("Result %s returned in %s seconds" % (sum, elapsed))

def findSum(limit):
    n1 = n2 = 1
    n3 = 2
    sum = 0

    while n3 < limit:
        if n3 % 2 == 0:
            sum += n3
        n1 = n2
        n2 = n3
        n3 = n1 + n2
    return sum

main()
