import random

def rwh_primes1(n):
    sieve = [True] * (int(n/2))
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i//2]:
            sieve[i*i//2::i] = [False] * ((n-i*i-1)//(2*i)+1)
    return [2] + [2*i+1 for i in range(1,n//2) if sieve[i]]

listOfPrimes = rwh_primes1(3164)

def prime(n):
    if n<2: return False
    if n==2: return True
    if n%2 == 0: return False
    for i in listOfPrimes:
        if i*i > n: return True
        if n%i==0: return False
    return True

n = int(input())
v = [int(x) for x in input().split()]

primes = []
rest = []

for i in range(n):
    if prime(v[i]): primes.append(i+1)
    else: rest.append(i+1)

random.shuffle(primes)
random.shuffle(rest)

#print(primes, rest)

tree = []

h = 1
while sum(2**i for i in range(h)) < n: h+=1

for _ in range(sum(2**i for i in range(h))): tree.append(0)

sumTree = tree[:]

#print(tree, sumTree)

for j in range(sum(2**i for i in range(h-1)), n):
    #print('inserting', sum(2**i for i in range(h-1)), n)
    if primes:
        tree[j] = primes[-1]
        primes.pop()
    else:
        tree[j] = rest[-1]
        rest.pop()
    sumTree[j] = tree[j]
    #print(tree)

rest = rest + primes
#print(rest)

for curH in range(h-1, 0, -1):
    for i in range(sum(2**x for x in range(curH-1)), sum(2**x for x in range(curH))):
        found = False
        for r in rest:
            #print('trying to add', r, 'at', i)
            if prime(r + sumTree[i*2 + 1] + sumTree[i*2+ 2]):
                #print('is prime, adding', r)
                tree[i] = r
                rest.remove(r)
                found = True
                break
        if not found:
            tree[i] = rest[-1]
            rest.pop()
        sumTree[i] = tree[i] + sumTree[2*i + 1] + sumTree[2*i + 2]
       #print(tree)

for i in range(n//2):
    if tree[i*2+1] != 0: print(tree[i], tree[2*i + 1])
    if tree[i*2+2] != 0: print(tree[i], tree[2*i + 2])
        
