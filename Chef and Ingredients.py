for _ in range(int(input())):
    n, k = (int(x) for x in input().split())
    l = k // n
    print((k - 1 + l*k - (n * l * (l + 1)) // 2) % 1000000007)