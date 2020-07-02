t = int(input())
for i in range(t):
    n, k = (int(x) for x in input().split())
    size = []
    for _ in range(n):
        size.append(int(input()))
    size.sort()
    diff = [size[i] - size[i-1] for i in range(1,n)]
    diff.sort()
    print(size[-1]-size[0]-sum(diff[n-k:]))



