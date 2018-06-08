#ProjectEuler: Problem 1
#Find the sum of all the multiples of 3 or 5 below 1000.
import time

def findSum(limit):
    sum = 0
    for num in range(3,limit,3): sum += num
    for num in range(5,limit,5):
        if num % 3: sum += num
    return sum
    
def main():
    limit = 1000
    start = time.time()
    print("Result %s returned in %s seconds" % (findSum(limit),time.time() - start))
main()
