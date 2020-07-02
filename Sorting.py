import random

def Sorted(a):
    for i in range(len(a)):
        if a[i] != i+1: return False
    return True

inp = open('sorting.in', 'r')
otp = open('sorting.out', 'w')
n = int(inp.readline())
a = [int(x) for x in inp.readline().split()]
swaps = []
while not Sorted(a):
    x = random.choice([i for i in range(n-1)])
    y = random.choice([i for i in range(x+1, n)])
    if a[x] > a[y]:
        a[x], a[y] = a[y], a[x]
        swaps.append([x+1, y+1])
otp.write(str(len(swaps))+'\n')
for s in swaps:
    otp.write(' '.join(str(x) for x in s) + '\n')
inp.close()
otp.close()
