class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pre(size+1);
        vector<int> post(size+1);
        pre[0] = 1;
        post[0] = 1;

        for (int i = 0; i < size; i ++){
            pre[i+1] = pre[i] * nums[i];
            post[i+1] = post[i] * nums[size-1-i];
        }

        for (int i = 0; i < size ; i++){
            pre[i] = pre[i] * post[size-(i+1)];
        }
        pre.pop_back();
        return pre;
    }
};

// Runtime: 31 ms
// Memory: 24.7 MB
// O(n)