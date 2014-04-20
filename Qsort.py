#!/usr/local/bin/python3

from sys import argv

def quicksort(a, left, right):
	if (left < right):
		pivotIdx = left + ((right - left) // 2)
		newPivotIdx = partition(a, left, right, pivotIdx)
		quicksort(a, left, newPivotIdx - 1)
		quicksort(a, newPivotIdx + 1, right)

def partition(a, left, right, pivotIdx):
	pivotVal = a[pivotIdx]
	swap(a, pivotIdx, right)
	storeIdx = left
	for i in range(left, right):
		if(a[i] < pivotVal):
			swap(a, i, storeIdx)
			storeIdx += 1
	swap(a, storeIdx, right)
	return storeIdx

def swap(a, x, y):
	tmp = a[x]
	a[x] = a[y]
	a[y] = tmp

def init_array(a, filename):
	iF = open(filename, "r")
	line = iF.readline()
	i = 0;
	while (line):
		a[i] = int(line)
		line = iF.readline()
		i+=1
	iF.close()

#def print_array(a, filename):
	#oF = open(filename, "w")
	#for i in range(0, len(a) - 1):
		#oF.write("{}\n".format(a[i]))
	#oF.close()
	
def pow_ten(idx):
	 if(idx == 0):
	      return 1
	 else:
	      return 10 * pow_ten(idx - 1)

def main():
		if(len(argv) != 2):
			print("Usage ./Qsort.py <powerOfTen>");
			return
		IDX = int(argv[1])
		ARRAY_SIZE = pow_ten(IDX)
		a = [None] * ARRAY_SIZE
		ifName = "10e{}.txt".format(IDX)
		#ofName = "10e{}sortedPY.txt".format(IDX)
		init_array(a, ifName)
		quicksort(a, 0, ARRAY_SIZE - 1)
		print("Sorted ",ARRAY_SIZE," ints in python.")
		#Used to test sorting
		#print_array(a, ofName)

main()
