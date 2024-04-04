#include <vector>
#include <string>
#include <iostream>


void moveZeroes(std::vector<int>& nums)
{
    if(nums.size()<=1)
        return;
    int i{0}, j{0};
    while(j < nums.size())
    {
        if(nums[j]!=0)
        {
            std::swap(nums[i],nums[j]);
            i++; //advance both if !=0
        }
        j++; //advance only curr if ==0
    }
}

int main()
{
    std::vector<int> nums={1,2,0,3,12};
    moveZeroes(nums);
    
    for(auto i : nums)
        std::cout << i << " " ;
}