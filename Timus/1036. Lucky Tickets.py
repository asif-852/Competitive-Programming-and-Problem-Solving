
def f(idx, digit_sum):
    if idx == 2 * n:
        return digit_sum == sum
    if idx == n and digit_sum != sum // 2:
        return 0
    if digit_sum > sum:
        return 0
    if dp[idx][digit_sum] != -1:
        return dp[idx][digit_sum]

    ret = 0
    for i in range(10):
        ret += f(idx + 1, digit_sum + i)
    
    dp[idx][digit_sum] = ret
    return ret

def solve():
    global n, sum
    n, sum = map(int, input().split())
    global dp
    dp = [[-1] * 901 for _ in range(100)]

    print(0 if (sum % 2 != 0) or (sum > 900) else f(0, 0))

if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()