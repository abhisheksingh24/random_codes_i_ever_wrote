def remain(n, k, extra):
    if n<=1: return 1
    if k<=0: return n
    if n%2: return remain((n+1)/2, k-1, True)
    if (n/2)%2 == 0 or extra: return remain(n/2, k-1, True)
    return remain(n/2 + 1, k-1, True)

for _ in range(int(input())):
    n, k = (int(x) for x in input().split())
    rem = (2 if n==2 else remain(n, k, False))
    print('{:.7f}'.format(1/rem))
    
