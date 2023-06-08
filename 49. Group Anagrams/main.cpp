class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> ret_vec;
        for (string& str: strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            hashmap[sorted].push_back(str);
        }
        
        for (auto& kv: hashmap){
            ret_vec.push_back(move(kv.second));
        }
        return ret_vec;
    }
};

//Runtime: 32 ms
// Memory: 18.4 MB
