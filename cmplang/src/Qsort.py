#!/usr/bin/env python3
from __future__ import with_statement
from sys import argv

def quicksort(a, left, right):
    if left < right:
        pivotIdx = left + ((right - left) // 2)
        newPivotIdx = partition(a, left, right, pivotIdx)
        quicksort(a, left, newPivotIdx - 1)
        quicksort(a, newPivotIdx + 1, right)


def partition(a, left, right, pivotIdx):
    pivotVal = a[pivotIdx]
    a[pivotIdx], a[right] = a[right], a[pivotIdx]
    storeIdx = left
    for i in range(left, right):
        if(a[i] < pivotVal):
            a[i], a[storeIdx] = a[storeIdx], a[i]
            storeIdx += 1

    a[storeIdx], a[right] = a[right], a[storeIdx]
    return storeIdx


def initArray(filename):
    with open(filename, 'r') as f:
        for line in f:
            yield int(line)


def printArray(a, filename):
    with open(filename, 'w') as f:
        f.write('\n'.join(str(n) for n in a))


def main(argc,argv):
    if (argc < 2) or (argc > 3):
        print("Usage ./Qsort.py <powerOfTen>")
        return
    IDX = int(argv[1])

    ifName = "10e%d.txt" % IDX
    a = list(initArray(ifName))
    quicksort(a, 0, len(a) - 1)
    #Used to test sorting
    if (argc == 3) and (argv[2] == "--print"):
        printArray(a, "10e%dsortedPY.txt" % IDX)
    print("Sorted %d ints in python." % len(a))

if __name__ == '__main__':
    main(len(argv),argv)
