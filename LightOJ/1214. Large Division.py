
t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    print(f"Case {i + 1}: ", end="")
    print("divisible" if a % b == 0 else "not divisible")
