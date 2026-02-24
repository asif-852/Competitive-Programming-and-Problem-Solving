class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = str()
        for u in s:
            if('a' <= u <= 'z' or 'A' <= u <= 'Z' or '0' <= u <= '9'):
                s1 += u.lower() if('A' <= u <= 'Z') else u
        return s1 == s1[::-1]