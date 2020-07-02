for _ in range(int(input())):
	n, k = (int(x) for x in input().split())
	i = 1
	if k==1: n = n % 2
	while n > 2*(k**i):
		n -= 2*(k**i) 
		i+=1
	if n == k**i or (n > k**i and n != 2*(k**i)): print('Alice')
	else: print('Bob')
