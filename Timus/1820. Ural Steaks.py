
n, k = map(int, input().split())
if(2 * n <= k):
    print(2)
elif((2 * n) % k == 0):
    print((2 * n) // k)
else:
    print((2 * n) // k + 1)