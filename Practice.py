for _ in range(int(input())):
    inp = input()
    while len(inp) == 0: inp = input()
    n, q = (int(x) for x in inp.split())
    inp = input()
    while len(inp) == 0: inp = input()
    p = [int(x) for x in inp.split()]
    inc = [0] * (n + 1)
    for qq in range(q):
        inp = input()
        while len(inp) == 0: inp = input()
        x, y = (int(xx) for xx in inp.split())
        inc[x - 1] += 1
        inc[y] -= 1
    cur = 0
    mx = 0
    ind = 0
    for i in range(0, n):
        cur += inc[i]
        if cur > mx:
            mx = cur
            ind = i
    print(p[ind])