from termcolor import colored

o = open("out/out" + "1" + ".out", "r").read()
r = open("rezultate/r" + "1" + ".out", "r").read()

l_o = len(o)
l_r = len(r)

if l_o > l_r:
    t = o
else:
    t = r

l_max = min(l_r, l_o)

for j in range(0,l_max):
    if o[j] != r[j]:
        print(colored(t[j], color='red'), end='')
    else:
        print(colored(t[j], color="green"), end='')