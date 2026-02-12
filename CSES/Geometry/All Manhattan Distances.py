
import sys
input = sys.stdin.readline


def solve():
    n = int(input())
    x = [0] * n
    y = [0] * n
    for i in range(n):
        x[i], y[i] = map(int, input().split())
    x.sort()
    y.sort()
    ans = 0
    prefix = 0
    for i in range(n):
        ans += x[i] * i - prefix
        prefix += x[i]
    prefix = 0
    for i in range(n):
        ans += y[i] * i - prefix
        prefix += y[i]
    print(ans)


t = 1
for _ in range(t):
    solve()
