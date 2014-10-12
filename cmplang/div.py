#!/usr/bin/env python3
#Because Bash can't do floating point division
from sys import argv

x = float(argv[1]) / float(argv[2])
print("%.4f" % round(x,4))
