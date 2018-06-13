#ProjectEuler: Problem 4
#Find the largest palindrome made from the product of two 3-digit numbers
import time

def main():
    start = time.time()
    for i in range(999*999, 1001, -1):
        if palindrome(i) and product(i):
            elapsed = time.time() - start
            print("Found largest palindrome %s in %s seconds" % (i, elapsed))
            break

def palindrome(num):
    return str(num) == str(num)[::-1]

def product(num):
    for i in range(999, 1, -1):
        if num % i == 0 and 100 < num / i and num / i < 999:
            return True
    return False

main()
