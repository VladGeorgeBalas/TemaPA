import sys

argv = sys.argv
argc = len(argv)

i = argv[1]
f = open(i, 'r')
for j in f.read().splitlines():
     j.rstrip()
     print(j)

