# coding:utf-8 
# Python implementation of Eudoxo Algorithm for square root
# @author Flávio Gomes da Silva Lisboa <flavio.lisboa@fgsl.eti.br>
#
import sys
from math import sqrt
import time

microtime = lambda: int(round(time.time() * 1000))

if len(sys.argv)<3:
    print "\nType: python eudoxo.py [number to extract root square] [number of iterations]\n"
    sys.exit()

p = int(sys.argv[1]) # square
n = int(sys.argv[2]) # iterations

start = microtime()

x = ((1 + p)/2)

print "\n n=0; x=" + str(x) + "\n"

for i in range(1,n):
	x = (((p/x) + x)/2)
	print "\n n=" + str(i) + "; x=" + str(x) + "; x^2=" + str(x * x) + "\n"

elapsedtime = microtime() - start

print "\nElapsed time: " + str(round(elapsedtime/1000,4)) + "ms\n"

print "\nValue of language function:" + str(sqrt(p)) + "\n" 

