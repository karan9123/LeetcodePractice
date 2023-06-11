class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(filter(str.isalnum, s))
        length = len(s)
        for i in range(length // 2):
            if s[i].lower() != s[length - i - 1].lower():
                return False

        return True
    
# Runtime: 103 ms
# Memory: 14.7 MB
# O(n)