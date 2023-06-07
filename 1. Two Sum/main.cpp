class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> my_map;
        for (int i = 0; i< nums.size(); i++){
            int temp = (target- nums[i]);
            if (my_map.count(temp) >0){
                return {i, my_map[temp]};
            }
            my_map.insert({nums[i], i});
        }
        return {0,0};
        
    }
};

// Runtime: 4 ms
// Memory: 10.8 MB
// 0(n)
