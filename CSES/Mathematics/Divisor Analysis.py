
MOD = 10**9 + 7
 
n = int(input())
x = []
k = []
 
for _ in range (n):
    xi, ki = map(int, input().split())
    x.append(xi)
    k.append(ki)
 
NOD = 1
for i in range (n):
    NOD *= (k[i] + 1)
    NOD %= MOD
 
SOD = 1
for i in range (n):
    temp = pow(x[i], k[i] + 1, MOD)
    temp -= 1
    temp *= pow(x[i] - 1, -1, MOD)
    SOD *= temp
    SOD %= MOD
 
POD = 1
odd_pos = next((idx for idx, value in enumerate(k) if value % 2 != 0), None)
exp = 1
for i in range (n):
    exp *= ((k[i] + 1) // 2 if i == odd_pos else (k[i] + 1))
    exp %= MOD - 1

num = 1
if odd_pos == None:
    k = [x // 2 for x in k]
for i in range (n):
    num *= pow(x[i], k[i], MOD)
    num %= MOD
POD = pow(num, exp, MOD)
 
print(NOD, SOD, POD)
