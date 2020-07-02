for _ in range(int(input())):
    n =  int(input())
    ar = [int(i) for i in input().split()]
    s = set(ar)
    odd = sum(i%2==1 for i in ar)
    even = sum(i%2==0 for i in ar)
    cnt = {}
    for i in ar:
        if i in cnt:
            cnt[i] += 1
        else:
            cnt[i] = 1
    two = sum(0 if i^2 not in cnt else cnt[i]*cnt[i^2] for i in s)/2
    zero = sum((cnt[i]*(cnt[i]-1))/2 for i in s)
    total = (odd*(odd-1))/2 + (even*(even-1))/2 - two - zero
    print(int(total))
        
    
