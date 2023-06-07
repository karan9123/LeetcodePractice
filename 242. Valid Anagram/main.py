class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import Counter
        return Counter(s) == Counter(t)
    
# Runtime: 63 ms
# Memory: 16.9 MB