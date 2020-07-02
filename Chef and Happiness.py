for _ in range(int(input())):
    n = int(input())
    a = [int(x)-1 for x in input().split()]
    pos = []
    cnt = []
    for _ in range(n):
        pos.append([])
        cnt.append(0)
    for i in range(n):
        pos[a[i]].append(i)
        cnt[a[i]]+=1
    found = False
    s = set(a)
    for i in s:
        if cnt[i] > 1:
            needed = 2
            for p in pos[i]:
                if cnt[p] > 0:
                    needed-=1
                if needed <= 0:
                    found = True
                    break
            if found: break
    
    if found: print('Truly Happy')
    else: print("Poor Chef")
