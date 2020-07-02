for _ in range(int(input())):
    n, k = (int(x) for x in input().split())
    a = [int(x) for x in input().split()]

    indexes = [0]
    cnt = 1
    
    for i in range(n):
        if a[i] > k:
            if cnt == 1 or a[i] != a[indexes[-1]-1]:
                indexes.append(i+1)
                cnt+=1

    indexes.append(n+1)
    cnt+=1

    #print(indexes)
    
    maxlen = 0
    
    for i in range(cnt-2):
        maxlen = max(indexes[i+2]-indexes[i]-1, maxlen)
    
    print(maxlen)
