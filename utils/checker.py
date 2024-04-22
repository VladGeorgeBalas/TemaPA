import subprocess

total = 0

for i in range(1, 15):
    #c, d, o, r
    c = "date/t" + str(i) + "/c.in"
    d = "date/t" + str(i) + "/d.in"
    o = "out/out" + str(i) + ".out"
    r = "rezultate/r" + str(i) + ".out"

    #ruleaza make build
    subprocess.run(["make"], capture_output = True)

    #ruleaza executabil
    subprocess.run(["./lanParty", c, d, o])

    #ruleaza make clean
    subprocess.run(["make", "clean"], capture_output = True)

    #compara r si o
    if open(o, mode = "rb").read() == open(r, mode = "rb").read():
        print("5pct")
        total += 5
    else:
        print("0")
        total += 0

print("total -> ", total)