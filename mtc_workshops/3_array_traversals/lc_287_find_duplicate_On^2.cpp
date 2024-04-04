#include <vector>
#include <string>
#include <iostream>


double findDuplicate(std::vector<int>& nums) {

    //MAIN IDEA: compare every element to every subsequent element, until a duplicate is found

    for(int i = 0; i < nums.size(); i++)
    {
        //compare nums[i] with every susequent element
        for(int j = i+1; j < nums.size(); j++)
        {
            if(nums[i] == nums[j])
                return nums[i];
        }
    }
    //no duplicate found
    return -1;
        
}

int main()
{
    std::vector<int> nums={3,1,3,4,2};
   
    std::cout << findDuplicate(nums) << std::endl;
   
}
