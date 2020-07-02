n, m, k = (int(x) for x in input().split())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
toLook = {}
for i in B:
    toLook[i] = 1
l = 0
r = 0
freq = {}
cnt = 0 
minm = 1000000
while l < n:
    while r < n and cnt < k:
        if A[r] in toLook:
            if A[r] in freq:
                if freq[A[r]] == 0:
                    cnt += 1
                freq[A[r]] += 1
            else:
                freq[A[r]] = 1
                cnt += 1
        r += 1
    if cnt >= k:
        if r - l < minm:
            minm = r - l
    else: break
    if A[l] in toLook:
        if A[l] in freq:
            if freq[A[l]] == 1:
                cnt -= 1
            freq[A[l]] -= 1
    l += 1

if minm == 1000000: minm = -1
print(minm)