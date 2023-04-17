import math
t = int(input())
# t= 1
for _ in range(t):
    q, a, b, c = map(int, input().split())
    if q == 1:
        print((a*b) % c)
    else:
        if b > c:
            b, c = c, b
        x = a // math.lcm(b,c)
        res = x*b + b - 1

        if a % b == a % c:
            res = res - (b - 1 - a % b)

        print(res)
