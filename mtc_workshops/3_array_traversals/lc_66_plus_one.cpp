#include <vector>
#include <string>
#include <iostream>


std::vector<int> plusOne(std::vector<int>& digits)
{   
    auto i{digits.size()-1};

    //read from least-significant (right-most)
    //if digit is a 9, carry over
    while(i > 0 and digits[i] >= 9)
    {
        digits[i] = 0;
        i--;
    }
    //increment
    digits[i]++;
    
    //if carried over up to most-significant digit
    //add another place value
    if(digits[0]>9)
    {
        digits.push_back(0);
        digits[0]=1;
    }
    return digits;
}

int main()
{
    std::vector<int> num={9,6,8,9};
    plusOne(num);
    
    for(auto i : num)
        std::cout << i << " " ;
}
