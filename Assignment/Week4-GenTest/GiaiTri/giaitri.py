import random
import os
def rand(a=1, b=1000):
    return random.randrange(a, b + 1)

def mu(a, b):
    if b == 1:
        return a
    if b == 0:
        return 1
    tmp = mu(a, b//2)
    tmp = tmp * tmp
    if b % 2 == 0:
        return tmp
    else:
        return tmp * a

TestNumber = 25
for i in range(12):
    os.mkdir(f"Test{i}")
    fi = open(f"./Test{i}/giaitri{i}.inp", "a+")
    fo = open(f"./Test{i}/giaitri{i}.out", "a+")
    t = rand(1, 200)
    fi.write(str(t) + '\n')


    for i in range(t):
        a, b = rand(), rand()
        fi.write(str(a) + " " + str(b) + '\n')
        res = mu(a, b) + mu(b, a)
        fo.write(str(res) + '\n')

    fi.close()
    fo.close()

for i in range(12, TestNumber):
    os.mkdir(f"Test{i}")
    fi = open(f"./Test{i}/giaitri{i}.inp", "a+")
    fo = open(f"./Test{i}/giaitri{i}.out", "a+")
    t = 200
    fi.write(str(t) + '\n')


    for i in range(t):
        a, b = rand(700, 1000), rand(700, 1000)
        fi.write(str(a) + " " + str(b) + '\n')
        res = mu(a, b) + mu(b, a)
        fo.write(str(res) + '\n')

    fi.close()
    fo.close()





