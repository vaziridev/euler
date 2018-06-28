#ProjectEuler: Problem 9
#Find the Pythagorean triplet for which a + b + c = 1000. Return product abc.
import time

def main():
    start = time.time()
    result = findProduct()
    elapsed = time.time() - start
    print("Product %s found in %s seconds" % (result, elapsed))

def findProduct():
    a = 1
    b = 2
    while True:
        c = 1000 - a - b

        if c <= b:
            a += 1
            b = a + 1
            continue
        elif c*c == a*a + b*b:
            product = a*b*c
            break
        else:
            b += 1
    return product

main()
