from itertools import permutations
n = int(input())
origList = [[i for i in range(1,n+1)]]
perms = [list(i) for i in list(permutations(origList[0]))]
print('permutations', perms)
for i in range(n):
    print(i,' : ', origList)
    newList = []
    for j in range(n):
        for perm in origList:
            #perm[i], perm[j] = perm[j], perm[i]
            newList.append(perm)
            newList[-1][i], newList[-1][j] = newList[-1][j], newList[-1][i]
    origList = newList.copy()

cnt = [0 for i in range(len(perms))]

for i in range(len(perms)):
    for p in origList:
        if p == perms[i]:
            cnt[i] += 1

mx = max(cnt)
mn = min(cnt)

print('maxes : ')
for i in range(len(cnt)):
    if cnt[i]==mx:
        print(perms[i])
print('mins: ')
for i in range(len(cnt)):
    if cnt[i] == mn:
        print(perms[i])
            

    
