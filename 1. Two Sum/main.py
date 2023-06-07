class Solution():
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        first_index: int = 0
        temp_var: int = 0
        num_counter: Counter[int] = Counter(nums)
        for index in range(0, len(nums)):
            if (num_counter[target - nums[index]] > 1) or (
                (num_counter[target - nums[index]] == 1) and (target - nums[index] != nums[index])):
                first_index = index
                temp_var = nums[index]
                break
        nums.remove(temp_var)
        second_index = nums.index(target - temp_var)
        if second_index >= first_index:
            second_index += 1
        return [first_index, second_index]
    
# Runtime: 58 ms
# Memory: 15.1 MB