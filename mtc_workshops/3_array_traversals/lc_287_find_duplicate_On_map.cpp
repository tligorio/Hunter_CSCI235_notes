#include <vector>
#include <string>
#include <iostream>
#include <map>


double findDuplicate(std::vector<int>& nums) {

    //MAIN IDEA: use a map to keep track of previously seen numbers

    std::map<int, int> count_map;

    for(int i = 0; i < nums.size(); i++)
    {
        count_map[nums[i]]++; //increment the value at key nums[i]
        if(count_map.at(nums[i]) > 1) // if incremented twice
            return nums[i];           // found
    }

    //no duplicate found
    return -1;
        
}

int main()
{
    std::vector<int> nums={1,3,4,4,2};
   
    std::cout << findDuplicate(nums) << std::endl;
   
}
