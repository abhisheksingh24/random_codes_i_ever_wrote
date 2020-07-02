for _ in range(int(input())):
    MOD = 1000000007
    n, k = (int(x) for x in input().split())
    if k==1:
        print((int)(n*n - n) % MOD)
        continue
    possible = True
    a = [i for i in range(1, k)]
    a.append(n - (k*(k-1))/2);
    if a[k-1] < k:
        print(-1)
        continue
    inc = (a[k-1] - a[k-2] - k + 1)//k;
    for i in range(k-1):
        a[i]+=inc
    a[k-1] -= (inc*(k-1))
    cnt = (int)(a[k-1] - a[k-2] - 2)
    if cnt > 0:
        for i in range(cnt):
            a[k-2-i]+=1
        a[k-1]-=cnt

    lim = k-2
    while True:
        r = -1
        for i in range(lim, 1, -1):
            if a[i] != a[i+1] -1:
                r = i
                break
        if r==-1:
            break
        x = 0
        y = r
        while x < y:
            a[x]-=1
            a[y]+=1
            x+=1
            y-=1
        lim = r
            
    res = 1
    for i in a:
        res= (res*(i*i - i))%MOD
    print((int)(res)%MOD)
