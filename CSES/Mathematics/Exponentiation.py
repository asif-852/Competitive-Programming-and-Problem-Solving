
MOD = 1000000007
for _ in range(int(input())):
    a, n = map(int, input().split())
    print(pow(a, n, MOD))
