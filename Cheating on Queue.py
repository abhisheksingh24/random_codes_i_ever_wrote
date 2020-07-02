def canStandAt(pos):
    global s, k
    s -= a[pos-1]//den[pos-1]
    den[pos-1] = a[pos-1] + 1
    for i in range(n):
        if s > k: return False
        id = order[i]
        if id < pos: continue
        s -= a[id]//den[id]
        den[id] = id - pos + 1
        s += a[id]//den[id]
    return s <= k
        
def custom_key(i):
    return -a[i]

for _ in range(int(input())):
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]
    den = [i for i in range(1, n+1)]
    frac = [a[i]//den[i] for i in range(n)]
    order = [i for i in range(n)]
    order.sort(key=custom_key)
    #print(order)
    s = sum(frac)
    if s <= k:
        print(1)
        continue
    pos = 1
    while pos < n:
        if canStandAt(pos): break
        pos+=1
    print(pos+1)
        