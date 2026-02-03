

def digit_sum(n):
    return sum(list(map(int,str(n).strip())))

s = input()
n1 = int(s[:3])
n2 = int(s[3:])
if(digit_sum(n1) == digit_sum(n2 + 1) or digit_sum(n1) == digit_sum(n2 - 1)):
    print("Yes")
else:
    print("No")

