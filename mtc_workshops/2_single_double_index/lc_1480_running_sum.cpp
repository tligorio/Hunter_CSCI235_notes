#include <vector>
#include <string>
#include <iostream>

std::vector<int> runningSum(std::vector<int>& nums)
{
    int sum{0};
    std::vector<int> running_sum{};

    for(auto i : nums)
    {
        sum+=i;
        running_sum.push_back(sum);
    }

    return running_sum;

}



int main()
{
    std::vector<int> nums={1,2,3,4};
    std::vector<int> rs = runningSum(nums);
    
    for(auto i : rs)
        std::cout << i << " " ;
}