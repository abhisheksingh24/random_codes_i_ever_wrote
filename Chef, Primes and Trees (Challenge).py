import sys
from atexit import register

if sys.version_info[0] < 3:
    from io import BytesIO as stream
else:
    from io import StringIO as stream


def sync_with_stdio(sync=True):
    """
    Sets whether the standard Python streams are allowed to buffer their I/O.
    Parameters
    ----------
    sync : bool, optional
        The new synchronization setting. Default is True.
    """
    global input, flush

    if sync:
        flush = sys.stdout.flush
    else:
        sys.stdin = stream(sys.stdin.read())
        input = lambda: sys.stdin.readline().rstrip('\r\n')

        sys.stdout = stream()
        register(lambda: sys.__stdout__.write(sys.stdout.getvalue()))

###############################################################################


import random

isPrime = [True]*(int(2e7) + 1)
isPrime[0] = isPrime[1] = False

def fillPrimes():
    for i in range(2, 4473):
        if not isPrime[i]: continue
        j = i*2
        while(j <= 10**7):
            isPrime[j] = False
            j+=i

fillPrimes()

def prime(n):
    return isPrime[n]

'''
n = 1000
v = [i+1 for i in range(20000)]
random.shuffle(v)
v = v[:1001]
'''

#print('Enter now')
n = int(input())
v = [int(x) for x in input().split()]


tot =sum(v)

remain = [i for i in range(n)]
inserted = []
parent = {}
sumSub = {}
children = {}

random.shuffle(remain)

def bestPlace(x, y, curProf):
    curProf += ((not prime(sumSub[x]) and prime(sumSub[x] + v[y])) + (not prime(tot - sumSub[x]) and prime(tot - sumSub[x] - v[y])) - (prime(sumSub[x]) and not prime(sumSub[x] + v[y])) - (prime(tot - sumSub[x]) and not prime(tot - sumSub[x] - v[y])))

    maxProf, loc, isParent = curProf, x, False

    for c in children[x]:
        profit, newLoc, isParent = bestPlace(c, y, curProf)
        if profit > maxProf:
            maxProf, loc = profit, newLoc 
    asChild = 0 + ((isPrime[v[y]])+(isPrime[tot-v[y]]))
    asParent = 0 + isPrime[sumSub[x] + v[y]] + isPrime[tot - sumSub[x] - v[y]]
    if curProf + asChild > maxProf: return curProf+asChild, x, False 
    if curProf + asParent> maxProf: return curProf+asParent, x, True
    return maxProf, loc, isParent

def fillSums(r):
    curSum = v[r]
    for c in children[r]:
        fillSums(c)
        curSum+=sumSub[c]
    sumSub[r] = curSum

#cnt = 1000
for r in remain:
    #print('left = ', cnt)
    #cnt-=1
    if not inserted:
        inserted.append(r)
        parent[r] = -1
        sumSub[r] = v[r]
        children[r] = []
        root = r
        continue
    bestProf, bestLoc, isParent = bestPlace(root, r, 0)
    if isParent:
        parent[r] = parent[bestLoc]
        parent[bestLoc] = r
        if parent[r]!=-1:
            children[parent[r]].remove(bestLoc)
            children[parent[r]].append(r)
        else: root = r
        children[r] = [bestLoc]
    else:
        parent[r] = bestLoc
        children[bestLoc].append(r)
        children[r] = []
    inserted.append(r)
    sumSub = {}
    fillSums(root)

    
for i in inserted:
    if parent[i] != -1: print(i+1, parent[i]+1)

'''
cnt = 0 
for i in inserted:
    if parent[i] != -1:
        if isPrime[sumSub[i]]: cnt+=1
        if isPrime[tot - sumSub[i]]: cnt+=1
print('\n\n', cnt)
'''
