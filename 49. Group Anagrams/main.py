class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret_dict = defaultdict(list)
        for val in strs:
            ret_dict[tuple(sorted(val))].append(val)
        return list( ret_dict.values())
    
# Runtime: 188 ms
# Memory: 18 MB