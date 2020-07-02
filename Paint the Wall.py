import bisect

for _ in range(int(input())):
    n, m = (int(x) for x in input().split())
    h  = [int(x) for x in input().split()]
    c  = [int(x) for x in input().split()]

    stateHeight = []
    stateColor = []
    
    for i in range(n):
        ind = bisect.bisect_right(stateHeight, h[i])
        stateHeight = [h[i]] + stateHeight[ind:]
        stateColor = [c[i]] + stateColor[ind:]

    print(len(set(stateColor)))
