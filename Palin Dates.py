def reverse(n):
    return n[1] + n[0]

def solve(d, m):
    if int(reverse(m)) > int(d) and int(reverse(m)) <= 60: return reverse(m), m
    m = str(int(m) % 30 + 1)
    if len(m) < 2: m = '0' + m
    while int(reverse(m)) > 60:
        m = str(int(m) % 30 + 1)
        if len(m) < 2: m = '0' + m
    return reverse(m), m

d, m = input().split(':')
d, m = solve(d, m)
print(d + ':' + m)
