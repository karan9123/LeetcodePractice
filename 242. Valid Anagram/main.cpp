class Solution {
public:
    bool isAnagram(string s, string t) {
        // checks if the length of strings are equal or not
        if (s.length() != t.length()){
            return false;
        }
        // hashmap stores the char as key and the number of occurances as value
        std::unordered_map<char, int> map_s;
        std::unordered_map<char, int> map_ti;
        for (size_t i = 0; i<=s.length(); i++){
            map_s[s[i]]++;
            map_ti[t[i]]++;
        }
        return (map_s == map_ti);
    }
};

// Runtime: 8 ms
// Memory: 7.4 MB