#include <vector>
#include <string>
#include <iostream>

void reverseString(std::vector<char>& s)
{
    for(int i = 0; i <= s.size()/2; i++)
        std::swap(s[i],s[s.size()-i-1]);
}

int main()
{
    std::vector<char> msg{'h','e','l','l','o'};
    reverseString(msg);
    
    for(auto c : msg)
        std::cout << c << " " ;
}