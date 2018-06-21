#ProjectEuler: Problem 6
#Find the difference between the sum of the squares and the square of the sum
#of the first 100 natural numbers
import time

start = time.time()
squareSum = sum(range(1,101)) ** 2 #

sumSquare = 1
for i in range(2,101):
    sumSquare += i ** 2

elapsed = time.time() - start
print("The difference of %s was found in %s seconds" % (squareSum - sumSquare, elapsed))
