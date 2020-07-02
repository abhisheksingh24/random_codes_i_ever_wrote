n = int(input())
h = [int(x) for x in input().split()]
c = [int(x) for x in input().split()]

m = []
for i in range(n - 1):
    m.append(h[i] < h[i + 1])  

print(sum(c[i] * m[i] for i in range(n - 1)))