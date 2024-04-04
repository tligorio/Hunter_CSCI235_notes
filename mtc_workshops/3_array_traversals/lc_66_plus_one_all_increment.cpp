#include <vector>
#include <string>
#include <iostream>


std::vector<int> plusOne(std::vector<int>& digits)
{   
    int remainder{1}, sum{0};

    //read from least-significant (right-most)
    //and add remainder
    for(int i = digits.size()-1; i >=0; i--)
    {
        sum = digits[i] + remainder;
        digits[i] = sum % 10;
        remainder = sum / 10;
    }
    
    
    //if still have remainder, add another place value
    if(remainder > 0)
        digits.insert(digits.begin(), remainder);
    
    return digits;
}

int main()
{
    std::vector<int> num={9,9,9,9};
    plusOne(num);
    
    for(auto i : num)
        std::cout << i << " " ;
}
