for _ in range(int(input())):
    n = int(input())
    s, x = input().split()
    pos = []
    l = len(s)
    for i in range(l):
        if s[i] == x:
            pos.append(i)
    cur = 0
    res = 0
    for p in pos:
        res += ((p - cur + 1) * (l - p))
        cur = p+1
    print(res)