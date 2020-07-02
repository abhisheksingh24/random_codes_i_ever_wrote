import atexit, io, sys
buffer = io.BytesIO() 
sys.stdout = buffer
@atexit.register 
def write(): 
    sys.__stdout__.write(buffer.getvalue()) 

n, q = (int(x) for x in input().split())
a = [int(input(), 2) for _ in range(n)]
for _ in range(q):
    inp = input().split()
    l, r, x = int(inp[0]), int(inp[1]), int(inp[2], 2)
    maxXOR = x^a[l-1]
    ind = l
    for i in range(l-1, r):
        if maxXOR < x^a[i]:
            maxXOR = x^a[i]
            ind = i+1
    print(ind)
    
    
