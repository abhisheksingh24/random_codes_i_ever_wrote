
#n, m = 10**5, 0
n, m = [int(x) for  x in input().split()]


#balloons = [10**9 for i in range(10**5)]
#candies = [10**9 for i in range(10**5)]
balloons = [int(x) for x in input().split()]
candies = [int(x) for x in input().split()]

shortage = sum(balloons) - m

def possible(x):
    s = shortage
    for i in range(n):
        if s <= 0:
            return True
        limit = x//candies[i]
        s-=min(limit,balloons[i])    
    return s<=0

def solve():
    if shortage <= 0:
        return 0
    l = 0
    r = 10**23
    while l < r:
        m = (l+r)//2
        #print(l, r, m)
        if(possible(m)):
            r = m
        else:
            l = m+1
    return l

#print('solving')
print(solve())

'''
def solve(l, r):
    if l==r:
        return l
    m = int((l+r)/2)
    if(possible(m)):
        return solve(l, m)
    return solve(m+1, r)

if shortage <= 0:
    print(0)

else:
    print(solve(0, shortage*max(candies)))

'''



