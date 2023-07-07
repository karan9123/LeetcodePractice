#include <iostream>
#include <vector>

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    
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