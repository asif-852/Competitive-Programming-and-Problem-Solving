
from decimal import Decimal, getcontext
getcontext().prec = 10
from math import gcd
 
def solve():
    s = input()
    i = s.find('.')
    cnt = int(0 if i == -1 else len(s[i+1:]))
 
    temp = int(pow(10, cnt))
    #print(f"temp = {temp}")
    #print(int(Decimal(s)*temp))
    #print(f"gcd = {gcd( int(Decimal(s)*temp) , temp)}")
    ans = temp / gcd(int(Decimal(s) * temp), temp)
    print(int(ans))
 
for _ in range(int(input())):
    solve() 