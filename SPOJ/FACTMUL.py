
MOD = 109546051211
N = 10000000

fact = [1] * (N + 1)
for i in range(1, N + 1):
    fact[i] = i * fact[i - 1]
    fact[i] %= MOD
 
n = int(input())
ans = 1
for i in range(1, n + 1):
    ans *= fact[i]
    ans %= MOD
print(ans)

