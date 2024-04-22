from termcolor import colored

for i in range(1, 1):
    #o, r
    o = open("out/out" + str(i) + ".out", "r").read()
    r = open("rezultate/r" + str(i) + ".out", "r").read()

    print(r)

    l_o = len(o)
    l_r = len(r)

    l_min = min(l_o, l_r)

    for j in l_min:
        if o[j] != r[j]:
            print(colored(o[j], color='red'))
        else:
            print(colored(o[j], color="green"))
