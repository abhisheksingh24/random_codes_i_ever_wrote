import random

def rwh_primes1(n):
    sieve = [True] * (int(n/2))
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1,n//2) if sieve[i]]

primes = rwh_primes1(3164)

def prime(n):
    if n<2: return False
    if n==2: return True
    if n%2 == 0: return False
    for i in primes:
        if i*i > n: return True
        if n%i==0: return False
    return True


'''
n = 1000
v = [i+1 for i in range(20000)]
random.shuffle(v)
v = v[:1001]
'''



n = int(input())
v = [int(x) for x in input().split()]


#score = 0

primeTrees = []
rest = []
for i in range(n):
    if prime(v[i]): primeTrees.append([i+1])
    else: rest.append(i+1)

checkNow = [i for i in range(len(primeTrees))]
checkNext = []

while checkNow:
    random.shuffle(checkNow)
    random.shuffle(primeTrees)
    random.shuffle(rest)
    newRest = []
    for r in rest:
        add = True
        for i in checkNow:
            if prime(sum(primeTrees[i]) + r):
                primeTrees[i].append(r)
                add = False
                checkNext.append(i)
                break
        if add: newRest.append(r)
    rest = newRest
    checkNow = checkNext
    checkNext = []

newPrimeTrees = []
inserted = [False]*1001

for i in rest:
    for j in rest:
        if i==j or inserted[i] or inserted[j]: continue
        if prime(v[i-1] + v[i-1]):
            newPrimeTrees.append([i, j])
            inserted[i] = True
            inserted[j] = True

rest = [i for i in rest if not inserted[i]]

checkNow = [i for i in range(len(newPrimeTrees))]
checkNext = []

while checkNow:
    random.shuffle(checkNow)
    random.shuffle(newPrimeTrees)
    random.shuffle(rest)
    newRest = []
    for r in rest:
        add = True
        for i in checkNow:
            if prime(sum(newPrimeTrees[i]) + r):
                newPrimeTrees[i].append(r)
                add = False
                checkNext.append(i)
                break
        if add: newRest.append(r)
    rest = newRest
    checkNow = checkNext
    checkNext = []


#print(primeTrees)
#print(rest)
for pp in primeTrees:
    for i in range(len(pp) - 1):
        print(pp[i], pp[i+1])
        #score+=1

for pp in newPrimeTrees:
    for i in range(len(pp) - 1):
        print(pp[i], pp[i+1])

random.shuffle(rest)
for i in range(len(rest) - 1):
    print(rest[i], rest[i+1])

if rest: root = rest[0]
elif primeTrees: root = primeTrees[-1][-1]
else: root = newPrimeTrees[-1][-1]

for pp in primeTrees:
    print(pp[-1], root)
    #score+=1

for pp in newPrimeTrees:
    print(pp[-1], root)


