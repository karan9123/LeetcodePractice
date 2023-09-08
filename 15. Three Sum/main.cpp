#include <iostream>
#include<algorithm>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    int size = sizeof(nums) / sizeof(nums[0]);
    if (size < 3){
        return result;
    }
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i< size; i ++){

    }
    
}

int main()
{
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    for(auto& num: threeSum(nums)){
        std::cout << std::endl;
        for(auto number: num){
            std::cout << number << ", ";
        }
    }
}