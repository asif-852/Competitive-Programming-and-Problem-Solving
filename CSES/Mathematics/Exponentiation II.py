
MOD = 1000000007
for _ in range(int(input())):
    a, b, c = map(int, input().split())
    n = pow(b, c, MOD - 1)
    print(pow(a, n, MOD))
