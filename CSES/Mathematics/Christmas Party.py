

#Approach 1

MOD = 1000000007
n = int(input())
d = [0] * (n + 2)
d[1] = 0
d[2] = 1
for i in range(3, n + 1):
	d[i] = (d[i - 1] + d[i - 2]) * (i - 1)
	d[i] %= MOD
print(d[n])

 
#Approach 2

'''
MOD = 1000000007
n = int(input())
d = [0] * (n + 2)
d[1] = 0
d[2] = 1
for i in range(3, n + 1):
	d[i] = i * d[i - 1] + (-1) ** i
	d[i] %= MOD
print(d[n])
'''