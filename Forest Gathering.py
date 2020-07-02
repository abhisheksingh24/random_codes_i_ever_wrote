def canCut(tym):
    sumFinalHeights = 0
    for i in height:
        finalHeight = i + height[i]*tym
        if finalHeight >= l:
            sumFinalHeights+=finalHeight
            if sumFinalHeights >= w:
                break
    return sumFinalHeights >= w

n, w, l = [int(x) for x in input().split()]
height = {}
for i in range(n):
    inp = input().split()
    height[int(inp[0])] = int(inp[1])

beg = -1
end = 10**18
while(end > beg+1):
    mid = int((beg+end)/2)
    if canCut(mid):
        end = mid
    else:
        beg = mid

print(end)
