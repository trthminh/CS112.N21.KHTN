import os
import random
import math

def Rand(a, b):
    return int(random.randrange(a, b + 1))

def solve(typeQuery, a, b, c):
    if typeQuery == 1:
        return ((a*b) % c)
    else:
        if b > c:
            b, c = c, b
        x = a // math.lcm(b,c)
        res = x*b + b - 1

        if a % b == a % c:
            res = res - (b - 1 - a % b)
        return res

TestNumber = 100
for _ in range(TestNumber):
    os.mkdir(f"Test{_}")
    fi = open(f"./Test{_}/modulo{_}.inp", "a+")
    fo = open(f"./Test{_}/modulo{_}.out", "a+")
    task1 = 20
    task2 = 40
    task3 = 60
    task4 = 100
    # Task 1
    if _ < 20: 
        q = Rand(10**4, 10**5)
        fi.write(str(q) + '\n')
        for i in range(q):
            typeQuery = 1
            a = Rand(1, 10**9)
            b = Rand(1, 10**9)
            c = Rand(1, 10**9)
            fi.write(str(typeQuery) + ' ' + str(a)+ ' ' + str(b)+ ' ' + str(c)+ '\n')
            fo.write(str(solve(typeQuery, a, b, c)))
    elif _ < 40:
        q = Rand(1, 10**3)
        for i in range(q):
            typeQuery = 2
            a = Rand(1, 10**4)
            b = Rand(1, 10**2)
            c = Rand(1, 10**2)
            fi.write(str(typeQuery) + ' ' + str(a)+ ' ' + str(b)+ ' ' + str(c)+ '\n')
            fo.write(str(solve(typeQuery, a, b, c)))
    elif _ < 60:
        q = Rand(10**4, 10**5)
        for i in range(q):
            typeQuery = Rand(1, 2)
            a = Rand(10**9 - 100, 10**9)
            b = Rand(1, min(a, 10**5))
            c = Rand(1, min(a, 10**5))
            fi.write(str(typeQuery) + ' ' + str(a)+ ' ' + str(b)+ ' ' + str(c)+ '\n')
            fo.write(str(solve(typeQuery, a, b, c)))
    else:
        q = Rand(10**4, 10**5)
        for i in range(q):
            typeQuery = Rand(1, 2)
            a = Rand(10**17, 10**18)
            b = Rand(1, min(a, 10**12))
            c = Rand(1, min(a, 10**12))
            fi.write(str(typeQuery) + ' ' + str(a)+ ' ' + str(b)+ ' ' + str(c)+ '\n')
            fo.write(str(solve(typeQuery, a, b, c)))
    
        
