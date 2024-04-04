#include <vector>
#include <string>
#include <iostream>


double findMaxAverage(std::vector<int>& nums, int k) {

    double max_sum{0.0};
    int first{0};

    //MAIN IDEA: use 2 indices, first and first+k-1, to delimit the current window of size k
    // first+k-1 is the end of a subarray of size k that starts at first, -1 because fist starts at 0
    // iteratively slide the window to the right by 1 (increment first)

    while((first+k-1) < nums.size())
    {
        double current_sum{0};
        //add up all the numbers in the current window
        for(int i=first; i<=(first+k-1); i++)
            current_sum+=nums[i];

        // check if the max sum so far is less than the sum of the current window 
        // and if so, replace it
        max_sum = std::max(max_sum, current_sum);
        first++;
    }
    //return the max average
    return max_sum/k;
        
}

int main()
{
    std::vector<int> nums={1,12,-5,-6,50,3};
    //std::vector<int> nums={5};
    int k{6};
    std::cout << findMaxAverage(nums,k) << std::endl;
   
}
