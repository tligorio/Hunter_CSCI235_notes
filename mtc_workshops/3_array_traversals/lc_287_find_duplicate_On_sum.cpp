#include <vector>
#include <string>
#include <iostream>
#include <numeric>


double findDuplicate(std::vector<int>& nums) {

    // MAIN ASSUMPTION: for a vector of size n, integers in vector are in range [1,n-1]
    // MAIN IDEA: given the assumption, the sum of the integers (without the duplicate) is 1 + 2 + ... + n-1 = (n-1 * n) /2
    // therefore the duplicate number is what is left in the total sum after subtracting (n-1 * n) /2

    auto n{nums.size()};

    int sum = std::accumulate(nums.begin(), nums.end(), 0); //accumulate is O(n)

    return sum - ((n-1)*n)/2;
        
}

int main()
{
    std::vector<int> nums={1,1,3,4,2};
   
    std::cout << findDuplicate(nums) << std::endl;
   
}
