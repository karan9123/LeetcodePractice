#include <vector>
#include <iostream>

class Solution
{
public:
    int findMin(std::vector<int> &nums)
    {
        int high = nums.size() - 1;
        int low = 0;
        int mid;
        while (low < high)
        {
            mid = static_cast<int>((low + high) / 2);
            if (nums[low] > nums[high])
            {
                if (nums[mid] > nums[high])
                {
                    if (low == mid)
                    {
                        low = high;
                    }
                    else
                    {
                        low = mid;
                    }
                }
                else 
                    {
                        high = mid;
                    }
            }

            if (nums[low] <= nums[high])
            {
                return nums[low];
            }
        }
        return nums[0];
    }
};

int main()
{
    std::vector<int> my_vec = {4, 5, 6, 7, 0, 1, 2, 3};
    Solution sol;
    std::cout << sol.findMin(my_vec);
    return 0;
}

//Runtime : 0 ms
// Memory : 10.1 MB
