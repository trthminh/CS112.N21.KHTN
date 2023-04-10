import math
t = int(input())
for _ in range(t):
    q, a, b, c = map(int, input().split())
    if q == 1:
        print((a*b) % c)
    else:
        res = min(b, c) - 1
        bc = ((b * c) // (math.gcd(b, c)))
        bc = a // bc
        res += bc  * min(b, c)

        print(res)
