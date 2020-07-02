def findLongest(beg):
    end = beg
    while end < n and [beg] == str[end]:
        end+=1
    return(end-beg, str[beg:end])

n = int(input())
str = input()

maxElements = []
nMax = 0
maxLen = 0
i = 0
while(i < n):
    len, subStr = findLongest(i)
    i+=len
    if len > maxLen:
        nMax = 1
        maxLen = len
        maxElemets = [subStr]
    elif len == maxLen:
        nMax+=1
        maxElements.append(subStr)

print(nMax)
for i in range(nMax):
    print(maxElements[i])
