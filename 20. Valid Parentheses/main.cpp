class Solution {
public:
   bool isValid(string s)
    {
        unordered_map<char, char> my_map{{']', '['}, {'}', '{'}, {')', '('}};
        stack<char> my_stack;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                my_stack.push(c);
            }
            else if (my_stack.empty() || my_stack.top() != my_map[c])
            {
                return false;
            }
            else
            {
                my_stack.pop();
            }
        }
        return (my_stack.empty());
    }
};

//Runtime: 0 ms  Beats 100%
// Memory: 6.3 MB Beats 78.94%