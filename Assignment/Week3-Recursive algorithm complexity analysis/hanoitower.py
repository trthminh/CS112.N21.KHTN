n = int(input())
def MoveDist(n):
    stack = [(n, 1, 3)]
    while stack:
        nDisk, src, dst = stack.pop()
        if nDisk == 1:
            print(f"Move disk from {src} to {dst}")
        else:
            mid = 6 - src - dst
            stack.append((nDisk - 1, src, mid))
            stack.append((1, src, dst))
            stack.append((nDisk - 1, mid, dst))

MoveDist(n)