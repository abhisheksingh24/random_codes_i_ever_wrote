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


n = 1000
v = [i+1 for i in range(20000)]
random.shuffle(v)
v = v[:1001]

#print('enter')

#n = int(input())
#v = [int(x) for x in input().split()]

tot =sum(v)

added = []
curTot = 0
remain = [i for i in range(n)]
sidechains = []
sidechainAttach = []
random.shuffle(remain)

while remain:
    done = False
    for r in remain:
        if isPrime[curTot + v[r]] and isPrime[tot - curTot - v[r]]:
            added.append(r)
            curTot += v[r]
            remain.remove(r)
            done = True
            break
    if done: continue
    if added:    
        for r in remain:
            if isPrime[curTot + v[r]] and isPrime[v[r]] and isPrime[tot-v[r]]:
                sidechains.append([r])
                sidechainAttach.append(added[-1])
                curTot += v[r]
                remain.remove(r)
                done = True
                break
        if done: continue
        for r in remain:
            if isPrime[curTot + v[r]]:
                for i in range(len(sidechains)):
                    if isPrime[v[r] + sum(v[x] for x in sidechains[i])] and isPrime[tot - v[r] - sum(v[x] for x in sidechains[i])]:
                        sidechains[i].append(r)
                        curTot += v[r]
                        remain.remove(r)
                        done = True
                        break                        
    if done: continue
    for r in remain:
        if isPrime[curTot + v[r]] or isPrime[tot - curTot - v[r]]:
            added.append(r)
            curTot += v[r]
            remain.remove(r)
            done = True
            break
    if done: continue
    added.append(remain[-1])
    curTot += v[remain[-1]]
    remain.pop()



for i in range(len(added) - 1):
    print(added[i]+1, added[i+1]+1)

for i in range(len(sidechains)):
    for j in range(len(sidechains[i]) - 1):
        print(sidechains[i][j]+1, sidechains[i][j+1] + 1)
    print(sidechains[i][0] + 1, sidechainAttach[i] + 1)

