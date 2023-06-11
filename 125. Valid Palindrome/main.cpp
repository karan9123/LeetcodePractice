class Solution
{
public:
    bool isPalindrome(string s)
    {
        int back = s.length() - 1;
        int front = 0;

        while (back > front)
        {
            if (isalnum(s[front]) && isalnum(s[back]))
            {
                if (tolower(s[front]) != tolower(s[back]))
                {
                    return false;
                }
                else
                {
                    front++;
                    back--;
                }
            }
            // else if (!isalnum(s[front]) && !isalnum(s[back]))
            // {
            //     front++;
            //     back--;
            // }
            else if (!isalnum(s[back]))
            {
                back--;
            }
            else if (!isalnum(s[front]))
            {
                front++;
            }
        }
        return true;
    }
};

// Runtime: 3 ms
// Memory: 7.2 MB
// O(n)