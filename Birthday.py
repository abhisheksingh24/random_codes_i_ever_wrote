n, m, k, l = (int(x) for x in input().split())
if l+k > n or m > n: print(-1)
else: print((l+k+m-1)//m)
