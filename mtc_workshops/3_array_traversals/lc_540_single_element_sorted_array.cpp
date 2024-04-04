#include <vector>
#include <string>
#include <iostream>


int singleNonDuplicate(std::vector<int>& nums) {

    int n{static_cast<int>(nums.size())}, mid{n/2}, first{0}, last{n-1};

    //IMPORTANT IDEA: a bunch of pairs of duplicates with one single element
    //implies that the vector or subvector containing the single element has odd size

    while(first < last)
    {
        //CASES:
        //single element in left subvector
        //case 1: _ _ _ mid X _ _
        if((nums[mid] == nums[mid + 1]) and (mid%2 == 1))
        {
            last = mid-1;
            mid = (last+first)/2;
        }
        //case 2:_ _ _ X mid _ _ _ _ 
        else if((nums[mid] == nums[mid - 1]) and (mid%2 == 0))
        {
            last = mid-2;
            mid = (last+first)/2;
        }
        //single element in right subvector
        //case 3: _ _ X mid _ _ _
        else if((nums[mid]== nums[mid -1 ]) and (mid%2 == 1))
        {
            first = mid+1;
            mid = (last+first)/2;
        }
        //case 4: _ _ _ _ mid X _ _ _
        else if((nums[mid]== nums[mid + 1]) and (mid%2 == 0))
        {
            first = mid+2;
            mid = (last+first)/2;
        }
        //found single element
        else
            return nums[mid];
    }
    return nums[mid];
        
}

int main()
{
    std::vector<int> num={1,2,2,3,3,4,4,8,8,9,9};
    std::cout << singleNonDuplicate(num) << std::endl;
   
}
