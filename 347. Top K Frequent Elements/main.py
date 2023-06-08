class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return (i for i, _ in collections.Counter(nums).most_common(k))
        
#  Runtime: 185 ms
#  Memory: 18.6 MB
# O(n)