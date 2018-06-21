#ProjectEuler: Problem 8
#Find the greatest product of 13 adjacent digits in the 1000-digit number
import sys
import time

#open file (008-number.txt)
filename = sys.argv[1]
txt = open(filename)

#read each number into its own list index
numlist = []
for line in txt:
    for number in line:
        if number != "\n":
            numlist.append(int(number))

#at each index up to and including # of digits - 13,
#multiply index with next 12 numbers and check if champion
largest = 0
i = 0
start = time.time()
while i <= len(numlist) - 13:
    product = 1
    for num in range(i, i + 13):
        #break if 0, no point continuing
        if numlist[i] == 0:
            break
        product *= numlist[num]
    if product > largest:
        largest = product
    i += 1

elapsed = time.time() - start
print("Found largest product %s in %s seconds" % (largest, elapsed))
