n, t = (int(x) for x in input().split())
a = [int(x) for x in input().split()]

tot = sum(a)
candies = 0

def solve(cur, nxt, l):
    if l<=0: return
    global candies
    global t
    global tot
    nxt = []
    revs = t//tot
    candies += (revs*l)
    t -= (revs*tot)
    for cost in cur:
        if cost <= t:
            t-=cost
            candies+=1
            nxt.append(cost)
        else:
            tot -= cost
            l-=1
    solve(nxt, cur, l)
                        
solve(a, [], n)
print(candies)
