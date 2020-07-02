import bisect

def present(nb):
    id = bisect.bisect(plant, nb)
    return(id == 0 or plant[id-1] != nb) 

def fenceBoundary():
    w = 0
    p = 0
    for i in range(1, n+1):
        if present((1, i)): w+=1
        else: p+=1
        if present((n, i)): w+=1
        else: p+=1
    for i in range(1, m+1):
        if present((i, 1)): w+=1
        else: p+=1
        if present((i, m)): w+=1
        else: p+=1 
    return p

def neighbour(p):
    x, y = p
    res = []
    if x-1 >= 1: res.append((x-1, y))
    if x+1 <= n: res.append((x+1, y))
    if y-1 >= 1: res.append((x, y-1))
    if y+1 <= m: res.append((x, y+1))
    return res

for _ in range(int(input())):
    n, m, k = (int(x) for x in input().split())
    plant = []
    for i in range(k):
        x, y = (int(x) for x in input().split())
        plant.append((x, y))
    plant.sort()
    cnt = 0
    for p in plant:
        for nb in neighbour(p):
            if present(nb): cnt+=1
    cnt += fenceBoundary()
    print(cnt)
