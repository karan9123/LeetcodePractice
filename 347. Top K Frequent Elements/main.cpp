class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> hashmap;
    vector<int> ret_vec;
    priority_queue<pair<int, int>> pq;

    for(int num : nums){
        hashmap[num]++;
    }
    for (auto& kv: hashmap){
        pq.push(make_pair(kv.second, kv.first));
    }

    for(int i = 0; i< k; i++){
        ret_vec.push_back(pq.top().second);
        pq.pop();
    }

    return ret_vec;

    }
};

// O(n)
// Runtime: 11 ms
// Memory :13.8 MB
