n = int(input())
s = input()
k = int(input())
str = ''
for e in s:
    asc = ord(e)
    for i in [97, 65]:
        if asc>=i and asc<i+26:
            str+=chr((asc-i+k)%26+i)
    else:
        str+=e
print(str)
