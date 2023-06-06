class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;

        for(size_t i {0}; i < nums.size(); i++){
            if (mySet.count(nums[i]) > 0){
                return true;
            }else{
                mySet.insert(nums[i]);
            }
        }
        return false;
    }
};