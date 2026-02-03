
n, m, y = map(int, input().split())
f = 0
for x in range(m):
    if(pow(x, n, m) == y):
        f = 1
        print(x, end=' ')

if(f == 0):
    print(-1)

