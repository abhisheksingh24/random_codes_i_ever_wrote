lst = [2**i for i in range(61)]

for _ in range(int(input())):
    n = int(input())
    print(min([abs(n - lst[i]) for i in range(61)]))
